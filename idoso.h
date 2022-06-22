#ifndef IDOSO_H
#define IDOSO_H

#include "local.h"

//define o tipo opaco Idoso
typedef struct idoso Idoso;

/*
    Inicializa um novo idoso
    Pré-condição: nenhuma
    Pós-condição: idoso criado 
*/
Idoso* inicIdoso(char* nome);

/*
    Lê uma linha do arquivo de entradas do idoso e atualiza suas informações
    Pré-condição: idoso existe
    Pós-condição: idoso atualizado a partir do arquivo de entrada dado 
*/
void atualizaIdoso(Idoso* idoso);

/*
    A partir das informações do idoso, escreve seu arquivo de saída
    Pré-condição: idoso existe
    Pós-condição: uma nova linha no arquivo de saída do idoso 
*/
void processaDadosIdoso(Idoso* idoso);

/*
    Imprime o nome do idoso na saída padrão
    Pré-condição: idoso existe
    Pós-condição: nenhuma
*/
void imprimeIdoso(Idoso* idoso);

/*
    Extrai o nome do idoso e o retorna.
    Pré-condição: idoso existe
    Pós-condição: nome retornado
*/
char* retornaNomeIdoso(Idoso* idoso);

/*
    Extrai o local do idoso e o retorna.
    Pré-condição: idoso existe
    Pós-condição: local retornado
*/
Localizacao* retornaLocalIdoso(Idoso* idoso);

/*
    Extrai o a lista de amigos do idoso e a retorna
    Pré-condição: idoso existe
    Pós-condição: lista de amigos retornada
*/
struct listaIdoso* obtemAmigosIdoso(Idoso* idoso);

/*
    Extrai o a lista de cuidadores do idoso e a retorna
    Pré-condição: idoso existe
    Pós-condição: lista de cuidadores retornada
*/
struct listaCuidador* obtemCuidadoresIdoso(Idoso* idoso);

/*
    libera a memória utilizada para um idoso
    Pré-condição: idoso existe
    Pós-condição: memória liberada
*/
void destroi_Idoso(Idoso* idoso);

/*
    retira o idoso de todas as listas(exceto uma lista mestre)
    e torna o idoso morto!
    Pré-condição: idoso existe
    Pós-condição: idoso existe apenas na lista mestre
*/
void faleceIdoso(Idoso* idoso);


#endif