#ifndef ListCuidador_H
#define ListCuidador_H

#include "cuidador.h"
#include "idoso.h"

//define o tipo opaco ListaCuidador
typedef struct listaCuidador ListCuidador;

/*
    Inicializa uma nova lista
    Pré-condição: nenhuma
    Pós-condição: lista criada
*/
ListCuidador* inicListaCuidador();

//cria o tipo cuidador dentro da função
/*
    função usada apenas na lista mestre de cuidadores
    Cria um novo cuidador e o insere dentro de uma lista
    Pré-condição: lista existe
    Pós-condição: cuidador criado e alocado na lista
*/
void insere_ElementoCuidador(ListCuidador* lista,char* nome);

/*
    função usada apenas em qualquer lista de cuidadores
    Insere um cuidador dentro de uma lista
    Pré-condição: lista e cuidadores existem
    Pós-condição: cuidador criado e alocado na lista
*/
void insereCuidador(ListCuidador* lista, Cuidador* cuidador);

/*
    Atualiza os cuidadores de uma lista a partir de um arquivo de entrada
    Pré-condição: lista existe
    Pós-condição: cuidadores atualizados
*/
void atualizaDadosListaCuidador(ListCuidador* lista);

/*
    A partir de um nome, encontra um cuidador em uma lista
    Pré-condição: lista existe
    Pós-condição: Cuidador encontrado(ou não!)
*/
Cuidador* buscaCuidador(ListCuidador* lista, char* nome);

/*
    Dado um idoso, encontra qual é o cuidador mais proximo dele
    e retorna seu nome.
    Pré-condição: lista e idosos existem
    Pós-condição: nome do cuidador mais próximo obtido
*/
char* obtemCuidadorMaisProximo(ListCuidador* lista, Idoso* idoso);

/*
    retira um cuidador de uma lista a partir de um nome
    Pré-condição: lista existe
    Pós-condição: cuidador retirado(se estiver na lista)
*/
void retiraCuidadorPorNome(ListCuidador* lista,char* nome);

/*
    imprime os nomes dos cuidadores de uma lista na saída padrão
    (função auxiliar para verificar os membros da lista)
    Pré-condição: lista existe
    Pós-condição: nenhuma
*/
void imprimeListaCuidador(ListCuidador* lista);

/*
    Destroi a lista mestre, deve ser utilizada apenas no fim do programa
    Pré-condição: lista existe
    Pós-condição: toda a memória liberada(cuidadores inclusos!)
*/
void destroiListaMestreCuidador(ListCuidador* lista);

/*
    Destroi uma lista 
    Pré-condição: lista existe
    Pós-condição: memória liberada(exceto dos cuidadores!)
*/
void destroiListaCuidador(ListCuidador* lista);

#endif