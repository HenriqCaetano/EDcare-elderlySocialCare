#include "cuidador.h"
#include "listaCuidador.h"
#include <stdlib.h>
#include <stdio.h>

struct Cel{
    Cuidador* cuidador;
    struct Cel* prox;
};

typedef struct Cel Celula;



struct listaCuidador{
    Celula* prim;
    Celula* ult;
};

ListCuidador* inicListaCuidador(){
    ListCuidador* lista = malloc(sizeof(ListCuidador));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void insereCuidador(ListCuidador* lista,Cuidador* cuidador);

void retiraCuidadorPorNome(ListCuidador* lista,Cuidador* cuidador);

void destroiListaCuidador(ListCuidador* lista);