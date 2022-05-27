#ifndef ListCuidador_H
#define ListCuidador_H

#include "cuidador.h"

typedef struct listaCuidador ListCuidador;

ListCuidador* inicListaCuidador();

void insereCuidador(ListCuidador* lista,Cuidador* cuidador);

void retiraCuidadorPorNome(ListCuidador* lista,Cuidador* cuidador);

void destroiListaCuidador(ListCuidador* lista);

#endif