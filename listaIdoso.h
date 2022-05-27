#ifndef LISTAIDOSO_H
#define LISTAIDOSO_H

#include "idoso.h"


typedef struct listaIdoso ListIdoso;

ListIdoso* inicListaIdoso();

void insereIdoso(ListIdoso* lista, Idoso* idoso);

void retiraIdosoPorNome(ListIdoso* lista, Idoso* idoso);

void destroiListaIdoso(ListIdoso* lista);

#endif