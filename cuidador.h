#ifndef CUIDADOR_H
#define CUIDADOR_H

#include "local.h"

typedef struct cuidador Cuidador;

Cuidador* inic_Cuidador(char* nome);

char* retornaNomeCuidador(Cuidador* cuidador);

Localizacao* retornaLocalCuidador(Cuidador* cuidador);

void atualizaCuidador(Cuidador* cuidador);

void imprimeCuidador(Cuidador* cuidador);

void destroiCuidador(Cuidador* cuidador);

#endif