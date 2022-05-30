#include "idoso.h"
#include "listaIdoso.h"
#include <stdlib.h>
#include <stdio.h>


struct Cel{
    Idoso* idoso;
    struct Cel* prox;
};
typedef struct Cel Celula;


struct listaIdoso{
    Celula* prim;
    Celula* ult;    
};


ListIdoso* inicListaIdoso(){
    ListIdoso* lista = malloc(sizeof(ListIdoso));
    
    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

//insere sempre na última posição
void insereIdoso(ListIdoso* lista, Idoso* idoso){
    Celula* nova = malloc(sizeof(Celula));
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
    Celula* p = lista->prim;

    for(p = lista->prim; p!= NULL; p = p->prox)
        imprimeIdoso(p->idoso);
}

void retiraIdosoPorNome(ListIdoso* lista, Idoso* idoso);

void destroiListaIdoso(ListIdoso* lista);