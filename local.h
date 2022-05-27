#ifndef LOCAL_H
#define LOCAL_H

typedef struct local Localizacao;


Localizacao* inicLocal(float latitude, float longitude);

float calculaDistancia(Localizacao* prim, Localizacao* seg);

void destroiLocal(Localizacao* local);

#endif