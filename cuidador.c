#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>
#include "cuidador.h"
#include "local.h"

struct cuidador{
    Localizacao* local;
    char* nome;
};

Cuidador* inic_Cuidador(float latitude, float longitude, char* nome){
    Cuidador* cuidador = malloc(sizeof(Cuidador));

    cuidador->local = inicLocal(latitude,longitude);
    cuidador->nome = strdup(nome);
    
    return cuidador;
}

void destroiCuidador(Cuidador* cuidador){
    if(cuidador != NULL){
        free(cuidador->nome);
        destroiLocal(cuidador->local);
        free(cuidador);
    }
}