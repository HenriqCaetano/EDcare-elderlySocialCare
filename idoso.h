#ifndef IDOSO_H
#define IDOSO_H

//#include "listaIdoso.h"

typedef struct idoso Idoso;

Idoso* inicIdoso(char* nome);

void atualizaIdoso(Idoso* idoso);

void imprimeIdoso(Idoso* idoso);

char* retornaNomeIdoso(Idoso* idoso);

struct listaIdoso* obtemAmigosIdoso(Idoso* idoso);

struct listaCuidador* obtemCuidadoresIdoso(Idoso* idoso);

void destroi_Idoso(Idoso* idoso);

void faleceIdoso(Idoso* idoso);


//void retiraCuidador(Idoso* idoso, Cuidador* cuidador);

#endif