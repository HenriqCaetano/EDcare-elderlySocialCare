#ifndef LISTAIDOSO_H
#define LISTAIDOSO_H

#include "idoso.h"

//define o tipo opaco ListIdoso
typedef struct listaIdoso ListIdoso;

/*
    inicializa uma lista de idosos
    Pré-condição: nenhuma
    Pós-condição: idosos criado
*/
ListIdoso* inicListaIdoso();

/*
    cria um idoso dentro de uma lista mestre e
    insere-o na lista(deve ser usado apenas na lista mestre)
    Pré-condição: lista existe
    Pós-condição: idoso criado e inserido na lista mestre
*/
void insereElemento(ListIdoso* lista, char* nome);

/*
    insere um idoso em uma lista qualquer
    Pré-condição: idoso e lista existem
    Pós-condição: idoso inserido na lista
*/
void insereIdoso(ListIdoso* lista, Idoso* idoso);

/*
    percorre os idosos de uma lista, atualizando as
    informações de cada um deles
    Pré-condição: a lista existe
    Pós-condição: idosos atualizados
*/
void atualizaDadosListaIdoso(ListIdoso* lista);

/*
    percorre os idosos de uma lista e escreve as saídas
    de cada um deles
    Pré-condição: a lista existe
    Pós-condição: saídas escritas corretamente no arquivo
    de saída de cada idoso
*/
void processaDadosListaIdoso(ListIdoso* lista);

/*
    encontra o amigo mais proximo de um idoso
    Pré-condição: lista e idoso existem
    Pós-condição: nenhuma
*/
char* obtemAmigoMaisProximo(ListIdoso* lista, Idoso* idoso);

/*
    percorre uma lista procurando um idoso
    Pré-condição: a lista existe
    Pós-condição: idoso encontrado(ou não!)
*/
Idoso* buscaIdoso(ListIdoso* lista, char* nome);

/*
    imprime os idosos de uma lista na saída padrão
    Pré-condição: a lista existe
    Pós-condição: nenhuma
    --função auxiliar para averiguar o estado de uma lista
*/
void imprimeListaIdosos(ListIdoso* lista);

/*
    inclui um idoso na lista de amigos do outro (e vice-versa)
    Pré-condição: a lista existe
    Pós-condição: um idoso na lista de amigos do outro(e vice-versa)
*/
void cria_AmizadeIdosos(ListIdoso* lista, char* amigo1, char* amigo2);

/*
    retira um idoso de uma lista
    Pré-condição: a lista existe
    Pós-condição: idoso retirado(se for encontrado)
*/
void retiraIdosoPorNome(ListIdoso* lista, char* nome);

/*
    destroi uma lista mestre(significa que destroi todos os idosos da lista)
    Pré-condição: a lista existe
    Pós-condição: memória dos idosos e da lista liberados!
*/
void destroiListaMestreIdoso(ListIdoso* lista);

/*
    libera a memória de uma lista(os idosos continuam existindo)
    Pré-condição: a lista existe
    Pós-condição: memória liberada e idosos ainda existem
*/
void destroiListaIdoso(ListIdoso* lista);

/*
    retira um idoso das listas de amigos dos seus amigos!
    usada quando um idoso morre
    Pré-condição: a lista existe
    Pós-condição: idoso desalocado das listas de amigos dos amigos
*/
void desfazAmizades(ListIdoso* amigos, char* nomeFalecido);

/*
    verifica se a lista está vazia
    Pré-condição: a lista existe
    Pós-condição: retorna 1 se a lista estiver vazia, 0 caso contrário
*/
int verificaListaVazia(ListIdoso* lista);

#endif