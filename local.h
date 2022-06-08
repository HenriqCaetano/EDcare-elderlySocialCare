#ifndef LOCAL_H
#define LOCAL_H

typedef struct local Localizacao;


Localizacao* inicLocal(float latitude, float longitude);

float calculaDistancia(Localizacao* prim, Localizacao* seg);

float retornaLatitude(Localizacao* local);

float retornaLongitude(Localizacao* local);

void atualizaLocalizacao(Localizacao* local,float latitude, float longitude);

void destroiLocal(Localizacao* local);

#endif