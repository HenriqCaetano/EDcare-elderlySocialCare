#include "cuidador.h"
#include "listaCuidador.h"
#include "idoso.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Cel{
    Cuidador* cuidador;
    struct Cel* prox;
};

typedef struct Cel CelulaC;

struct listaCuidador{
    CelulaC* prim;
    CelulaC* ult;
};

ListCuidador* inicListaCuidador(){
    ListCuidador* lista = (ListCuidador*) malloc(sizeof(ListCuidador));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insere_ElementoCuidador(ListCuidador* lista, char* nome){
    Cuidador* cuidador = inic_Cuidador(nome);
    CelulaC* nova = (CelulaC*)malloc(sizeof(CelulaC));
    nova->cuidador = cuidador;
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

void insereCuidador(ListCuidador* lista, Cuidador* cuidador){
    CelulaC* nova = (CelulaC*)malloc(sizeof(CelulaC));
    nova->cuidador = cuidador;
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

void atualizaDadosListaCuidador(ListCuidador* lista){
    CelulaC* atual;

    for(atual = lista->prim; atual != NULL; atual =atual->prox){
        atualizaCuidador(atual->cuidador);
    }
}

Cuidador* buscaCuidador(ListCuidador* lista, char* nome){
    CelulaC* p;

    for(p=lista->prim; p != NULL; p = p->prox){
        if(strcmp(retornaNomeCuidador(p->cuidador),nome) == 0) break;
    }
    return p->cuidador;
}

char* obtemCuidadorMaisProximo(ListCuidador* lista, Idoso* idoso){
    CelulaC* atual;
    float menorDistancia = __INT_MAX__;//pode dar problema, talvez um valor maior resolve
    float distAtual;
    char* cuidadorProximo;
    
    for(atual= lista->prim; atual != NULL; atual=atual->prox){
        distAtual = calculaDistancia(retornaLocalCuidador(atual->cuidador),retornaLocalIdoso(idoso));

        if(distAtual < menorDistancia){
            cuidadorProximo = retornaNomeCuidador(atual->cuidador);
            menorDistancia = distAtual;
        }
    }
    return cuidadorProximo;
}

void retiraCuidadorPorNome(ListCuidador* lista,char* nome){
    CelulaC* p, *ant;

    for(p = lista->prim; p!= NULL; p = p->prox){
        if(strcmp(nome, retornaNomeCuidador(p->cuidador)) == 0){
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

void imprimeListaCuidador(ListCuidador* lista){
    CelulaC* p = lista->prim;

    for(p = lista->prim; p!= NULL; p = p->prox)
        imprimeCuidador(p->cuidador);
}

void destroiListaMestreCuidador(ListCuidador* lista){
    CelulaC* p, *temp;

    for(p= lista->prim;p != NULL; p = temp){
        temp = p->prox;
        destroiCuidador(p->cuidador);
        free(p);
    }
    free(lista);
}

void destroiListaCuidador(ListCuidador* lista){
    CelulaC* p, *temp;

    for(p= lista->prim;p != NULL; p = temp){
        temp = p->prox;
        free(p);
    }
    free(lista);
}