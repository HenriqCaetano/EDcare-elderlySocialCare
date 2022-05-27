#include "local.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct local{
    float latitude;
    float longitude;
};

Localizacao* inicLocal(float latitude, float longitude){
    Localizacao* local = malloc(sizeof(Localizacao));

    local ->latitude = latitude;
    local->longitude = longitude;

    return local;
}

float calculaDistancia(Localizacao* prim, Localizacao* seg){
    return  sqrt(pow((prim->latitude - seg->latitude),2) + pow((prim->longitude - seg->longitude),2));
}

void destroiLocal(Localizacao* local){
    if(local != NULL) free(local);
}