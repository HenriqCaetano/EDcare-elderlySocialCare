#ifndef ListCuidador_H
#define ListCuidador_H

#include "cuidador.h"

typedef struct listaCuidador ListCuidador;

ListCuidador* inicListaCuidador();

void insereCuidador(ListCuidador* lista,char* nome);

void retiraCuidadorPorNome(ListCuidador* lista,char* nome);

void imprimeListaCuidador(ListCuidador* lista);

void destroiListaCuidador(ListCuidador* lista);

#endif