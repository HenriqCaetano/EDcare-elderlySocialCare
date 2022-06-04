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

//recebe o nome de um idoso e cria o tipo idoso dentro da função
void insereElemento(ListIdoso* lista, char* nome){
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

//recebe um idoso já criado e insere na lista
void insereIdoso(ListIdoso* lista, Idoso* idoso){
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

Idoso* buscaIdoso(ListIdoso* lista, char* nome){
    CelulaI *p;

    for(p = lista->prim; p!= NULL; p=p->prox){
         if(strcmp(nome, retornaNomeIdoso(p->idoso)) == 0){
            break;
        }
    }
    return p->idoso;
}

void imprimeListaIdosos(ListIdoso* lista){
    CelulaI* p = lista->prim;

    for(p = lista->prim; p!= NULL; p = p->prox)
        imprimeIdoso(p->idoso);
}



void cria_AmizadeIdosos(ListIdoso* lista, char* amigo1, char* amigo2){
    CelulaI  *ids1, *ids2;

    for(ids1 = lista->prim; ids1!= NULL; ids1 = ids1->prox){
        if(strcmp(amigo1, retornaNomeIdoso(ids1->idoso)) == 0){
            break;
        }
    }
    if(ids1 == NULL) return;//não encontrou
    //ids1 é o ponteiro para o primeiro idoso
    //necessário encontrar o segundo:
    for(ids2 = lista->prim; ids2!= NULL; ids2 = ids2->prox){
        if(strcmp(amigo2, retornaNomeIdoso(ids2->idoso)) == 0){
            break;
        }
    }
    if(ids2 == NULL) return;//não encontrou
    //ids2 é o ponteiro para o segundo idoso

    //adiciona ids2 na lista de amigos de ids1
    insereIdoso(obtemAmigosIdoso(ids1->idoso), ids2->idoso);
    //adiciona ids1 na lista de amigos de ids2
    insereIdoso(obtemAmigosIdoso(ids2->idoso), ids1->idoso);

    //imprimeListaIdosos(obtemAmigosIdoso(ids1->idoso));
    return;
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