#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#include "local.h"
#include "idoso.h"
#include "listaIdoso.h"
#include "listaCuidador.h"

#define input "./Testes/Testes/Teste1/Entradas/"
#define output "./Testes/Testes/Teste1/outputs/"

struct idoso
{
    char* nome;
    float temperatura;
    int queda;
    int morte;
    int contaFebre;
    Localizacao* local;
    ListCuidador* cuidadores;
    ListIdoso* amigos;
    FILE* arqEnt;
    FILE* arqSaida;
};

Idoso* inicIdoso(char* nome){
    
    Idoso* idoso = (Idoso*) malloc(sizeof(Idoso));

    idoso->nome = strdup(nome);
    idoso->temperatura= 0;
    idoso->queda = 0;
    idoso->morte = 0;
    idoso->contaFebre = 0;
    idoso->local = inicLocal(0, 0);

    idoso->cuidadores = inicListaCuidador();
    idoso->amigos = inicListaIdoso();

    char in[100] = "\0", out[100] = "\0";
    strcat(in,input);
    strcat(in,nome);
    strcat(in,".txt");

    strcat(out,output);
    strcat(out,nome);
    strcat(out,"-saida.txt");

    idoso->arqEnt = fopen(in,"r");
    idoso->arqSaida = fopen(out,"w");

    return idoso;
}

void atualizaTemperaturaIdoso(Idoso* idoso, float temperatura){
    idoso->temperatura = temperatura;
    return;
}

void atualizaQuedaIdoso(Idoso* idoso, int queda){
    idoso->temperatura = queda;
    return;
}

void atualizaMorteIdoso(Idoso* idoso, int morte){
    idoso->temperatura = morte;
    return;
}

void atualizaLocalizacaoIdoso(Idoso* idoso, float latitude, float longitude){
    atualizaLocalizacao(idoso->local, latitude, longitude);
    return;
}

void incrementaContaFebreIdoso(Idoso* idoso){//provavelmente necessita mudança!!
    if(idoso->contaFebre == 3) idoso->contaFebre = 0;
    else idoso->contaFebre++;
    return;
}


void imprimeIdoso(Idoso* idoso){
    printf("NOME: %s\n", idoso->nome);
}

ListIdoso* obtemAmigosIdoso(Idoso* idoso){
    return idoso->amigos;
}

ListCuidador* obtemCuidadoresIdoso(Idoso* idoso){
    return idoso->cuidadores;
}


char* retornaNomeIdoso(Idoso* idoso){
    return idoso->nome;
}

void destroi_Idoso(Idoso* idoso){
    if(idoso != NULL){
        destroiLocal(idoso->local);
        destroiListaCuidador(idoso->cuidadores);
        destroiListaIdoso(idoso->amigos);
        free(idoso->nome);
        free(idoso);
    }
}   
void faleceIdoso(Idoso* idoso);