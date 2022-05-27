#ifndef IDOSO_H
#define IDOSO_H

typedef struct idoso Idoso;

Idoso* inicIdoso(char* nome, float temperatura, int queda, int morte, int contaFebre,
float latitude, float longitude, ListCuidador* cuidadores, ListIdoso* amigos);

void adiciona_Amigo(Idoso* idoso, Idoso* amigo);

void retira_Amigo(Idoso* idoso, Idoso* amigo);

void adicionaCuidador(Idoso* idoso, Cuidador* cuidador);


void atualizaIdoso();

void faleceIdoso(Idoso* idoso);


//void retiraCuidador(Idoso* idoso, Cuidador* cuidador);

#endif