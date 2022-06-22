#include "local.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct local{
    float latitude;
    float longitude;
};

Localizacao* inicLocal(float latitude, float longitude){
    Localizacao* local = (Localizacao*)malloc(sizeof(Localizacao));

    local ->latitude = latitude;
    local->longitude = longitude;

    return local;
}

float retornaLatitude(Localizacao* local){
    if(!local) exit(1);
    return local->latitude;
}

float retornaLongitude(Localizacao* local){
    if(!local) exit(1);
    return local->longitude;
}

void atualizaLocalizacao(Localizacao* local,float latitude, float longitude){
    if(!local) return;
    local->latitude = latitude;
    local->longitude = longitude;
}

float calculaDistancia(Localizacao* prim, Localizacao* seg){
    if(!prim || !seg) exit(1);
    return  sqrt(pow((prim->latitude - seg->latitude),2) + pow((prim->longitude - seg->longitude),2));
}

void destroiLocal(Localizacao* local){
    if(local != NULL) free(local);
}