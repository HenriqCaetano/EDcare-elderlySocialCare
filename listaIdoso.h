#ifndef LISTAIDOSO_H
#define LISTAIDOSO_H

#include "idoso.h"


typedef struct listaIdoso ListIdoso;

ListIdoso* inicListaIdoso();

void insereIdoso(ListIdoso* lista, char* nome);

void imprimeListaIdosos(ListIdoso* lista);

void retiraIdosoPorNome(ListIdoso* lista, char* nome);

void destroiListaIdoso(ListIdoso* lista);

#endif