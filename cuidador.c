#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include "cuidador.h"
#include "local.h"
#include <stdio.h>

#define input "./Testes/Testes/Teste1/Entradas/"

struct cuidador{
    Localizacao* local;
    char* nome;
    FILE* arqEnt;
};

Cuidador* inic_Cuidador(char* nome){
    Cuidador* cuidador = (Cuidador*)malloc(sizeof(Cuidador));

    cuidador->nome = strdup(nome);
    cuidador->local = inicLocal(0,0);

    char in[100] = "\0";
    strcat(in,input);
    strcat(in,nome);
    strcat(in,".txt");

    cuidador->arqEnt = fopen(in,"r");

    return cuidador;
}

void imprimeCuidador(Cuidador* cuidador){
    printf("NOME CUIDADOR: %s\n",cuidador->nome);
}

void atualizaCuidador(Cuidador* cuidador){
    char* entrada, *dado;
    float lat,lon;
    fscanf(cuidador->arqEnt,"%s", entrada);
    
    dado = strtok(entrada,";");//obtém a latitude
    lat = atof(dado);
    dado = strtok(NULL,";");
    lon = atof(dado);
    atualizaLocalizacao(cuidador->local,lat,lon);

    //VERIFICAR SE OS DADOS OBTIDOS FORAM COMPATÍVEIS!!
    printf("atualizou %s\n",cuidador->nome);
    return;
}

char* retornaNomeCuidador(Cuidador* cuidador){
    return cuidador->nome;
}

void destroiCuidador(Cuidador* cuidador){
    if(cuidador != NULL){
        free(cuidador->nome);
        destroiLocal(cuidador->local);
        free(cuidador);
    }
}
