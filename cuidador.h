#ifndef CUIDADOR_H
#define CUIDADOR_H

#include "local.h"

//define o tipo opaco Cuidador
typedef struct cuidador Cuidador;

/*
    inicializa um cuidador
    Pré-condição: nenhuma
    Pós-condição: cuidador inicializado
*/
Cuidador* inic_Cuidador(char* nome);

/*
    retorna o nome do cuidador
    Pré-condição: cuidador existe
    Pós-condição: nenhuma
*/
char* retornaNomeCuidador(Cuidador* cuidador);

/*
    obtem o local de um cuidador
    Pré-condição: o cuidador existe
    Pós-condição: nenhuma
*/
Localizacao* retornaLocalCuidador(Cuidador* cuidador);

/*
    atualiza um cuidador de acordo com o arquivo de entrada dado
    Pré-condição: o cuidador existe
    Pós-condição: o cuidador foi atualizado
*/
void atualizaCuidador(Cuidador* cuidador);

/*
    imprime o nome de um cuidador
    Pré-condição: o cuidador existe
    Pós-condição: nenhuma
*/
void imprimeCuidador(Cuidador* cuidador);

/*
    libera a memória de um cuidador
    Pré-condição: o cuidador existe
    Pós-condição: toda a memória liberada
*/
void destroiCuidador(Cuidador* cuidador);

#endif