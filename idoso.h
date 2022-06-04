#ifndef IDOSO_H
#define IDOSO_H

typedef struct idoso Idoso;

Idoso* inicIdoso(char* nome);


void atualizaTemperaturaIdoso(Idoso* idoso, float temperatura);

void atualizaQuedaIdoso(Idoso* idoso, int queda);

void atualizaMorteIdoso(Idoso* idoso, int morte);

void atualizaLocalizacaoIdoso(Idoso* idoso, float latitude, float longitude);

void incrementaContaFebreIdoso(Idoso* idoso);

void imprimeIdoso(Idoso* idoso);

char* retornaNomeIdoso(Idoso* idoso);

void destroi_Idoso(Idoso* idoso);

void faleceIdoso(Idoso* idoso);


//void retiraCuidador(Idoso* idoso, Cuidador* cuidador);

#endif