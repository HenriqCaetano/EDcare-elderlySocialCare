#include "idoso.h"
#include "cuidador.h"
#include "listaCuidador.h"
#include "listaIdoso.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Idoso* a = inicIdoso("Paulo");
    Idoso* b = inicIdoso("Joao");
    Idoso* c = inicIdoso("Henrique");

    ListIdoso* idosos = inicListaIdoso();

    insereIdoso(idosos,a);
    insereIdoso(idosos,b);
    insereIdoso(idosos,c);


    imprimeListaIdosos(idosos);

    printf("APÓS:\n");

    retiraIdosoPorNome(idosos, c);
    imprimeListaIdosos(idosos);

    destroiListaIdoso(idosos);
    
    return 0;
}