#ifndef ListCuidador_H
#define ListCuidador_H

#include "cuidador.h"

typedef struct listaCuidador ListCuidador;

ListCuidador* inicListaCuidador();

//cria o tipo cuidador dentro da função
void insere_ElementoCuidador(ListCuidador* lista,char* nome);

//apenas insere o cuidador na lista
void insereCuidador(ListCuidador* lista, Cuidador* cuidador);

Cuidador* buscaCuidador(ListCuidador* lista, char* nome);

void retiraCuidadorPorNome(ListCuidador* lista,char* nome);

void imprimeListaCuidador(ListCuidador* lista);

void destroiListaCuidador(ListCuidador* lista);

#endif