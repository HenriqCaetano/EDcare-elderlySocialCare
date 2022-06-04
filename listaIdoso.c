#include "idoso.h"
#include "listaIdoso.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Cel{
    Idoso* idoso;
    struct Cel* prox;
};
typedef struct Cel CelulaI;


struct listaIdoso{
    CelulaI* prim;
    CelulaI* ult;    
};


ListIdoso* inicListaIdoso(){
    ListIdoso* lista = (ListIdoso*)malloc(sizeof(ListIdoso));
    
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

//insere sempre na última posição
void insereIdoso(ListIdoso* lista, char* nome){
    Idoso* idoso = inicIdoso(nome);
    CelulaI* nova = (CelulaI*)malloc(sizeof(CelulaI));
    nova->idoso = idoso;
    nova->prox = NULL;

    if(lista->prim == NULL && lista->ult == NULL){//caso lista vazia
        lista->prim = nova;
        lista->ult = nova;
    }
    else{//caso comum
        lista->ult->prox = nova;
        lista->ult = nova;
    }
}

void imprimeListaIdosos(ListIdoso* lista){
    CelulaI* p = lista->prim;

    for(p = lista->prim; p!= NULL; p = p->prox)
        imprimeIdoso(p->idoso);
}


void retiraIdosoPorNome(ListIdoso* lista, char* nome){
    CelulaI* p, *ant;

    for(p = lista->prim; p!= NULL; p = p->prox){
        if(strcmp(nome, retornaNomeIdoso(p->idoso)) == 0){
            break;
        }
        ant = p;
    }
    if(p == NULL) return;//não encontrou

    //se encontrou:
    //caso unico da lista
    if(lista->prim == lista->ult){
        lista->prim = NULL;
        lista->ult = NULL;
        free(p);
    }

    //caso primeiro da lista
    else if(p == lista->prim){
        lista->prim = p->prox;
        free(p);
    }

    //caso ultimo da lista
    else if(p == lista->ult){
        lista->ult = ant;
        ant->prox = NULL;
        free(p);
    }
    
    //caso comum
    else{
        ant->prox = p->prox;
        free(p);
    }
}

//libera o idoso junto, uso na lista mestre do programa
void destroiListaIdoso(ListIdoso* lista){
    CelulaI* p, *temp;

    for(p= lista->prim;p != NULL; p = temp){
        temp = p->prox;
        destroi_Idoso(p->idoso);
        free(p);
    }
    free(lista);
}