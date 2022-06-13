#ifndef LISTAIDOSO_H
#define LISTAIDOSO_H

#include "idoso.h"

typedef struct listaIdoso ListIdoso;

ListIdoso* inicListaIdoso();

void insereElemento(ListIdoso* lista, char* nome);

void insereIdoso(ListIdoso* lista, Idoso* idoso);

void atualizaDadosListaIdoso(ListIdoso* lista);

void processaDadosListaIdoso(ListIdoso* lista);

char* obtemAmigoMaisProximo(ListIdoso* lista, Idoso* idoso);

Idoso* buscaIdoso(ListIdoso* lista, char* nome);

void imprimeListaIdosos(ListIdoso* lista);

void cria_AmizadeIdosos(ListIdoso* lista, char* amigo1, char* amigo2);

void retiraIdosoPorNome(ListIdoso* lista, char* nome);

void destroiListaMestreIdoso(ListIdoso* lista);

void destroiListaIdoso(ListIdoso* lista);

void desfazAmizades(ListIdoso* amigos, char* nomeFalecido);

int verificaListaVazia(ListIdoso* lista);

#endif