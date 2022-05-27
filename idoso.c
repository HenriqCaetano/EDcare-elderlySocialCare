#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "local.h"
#include "idoso.h"
#include "listaIdoso.h"
#include "listaCuidador.h"



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
};

Idoso* inicIdoso(char* nome, float temperatura, int queda, int morte, int contaFebre,
float latitude, float longitude, ListCuidador* cuidadores, ListIdoso* amigos){
    
    Idoso* idoso = malloc(sizeof(idoso));

    idoso->nome = strdup(nome);
    idoso->temperatura= temperatura;
    idoso->queda = 0;
    idoso->morte = 0;
    idoso->contaFebre = 0;
    idoso->local = inicLocal(latitude, longitude);

    idoso->cuidadores = inicListaCuidador();
    idoso->amigos = inicListaIdoso();

    return idoso;

}

void atualizaIdoso();


void faleceIdoso(Idoso* idoso);

