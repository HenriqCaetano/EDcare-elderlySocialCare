#include "idoso.h"
#include "cuidador.h"
#include "listaCuidador.h"
#include "listaIdoso.h"
#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>

#define entradas "./Testes/Testes/Teste1/Entradas"

int main(int argc, char* argv){
    char *atual, *prox, input[50];

    //duas listas mestres!
    ListIdoso* idosos = inicListaIdoso();
    ListCuidador* cuidadores = inicListaCuidador();
    
    FILE* arqApoio = fopen(entradas"/apoio.txt","r");

    //verifica se o arquivo foi aberto com sucesso
    if(!arqApoio) return 1;
    

    fscanf(arqApoio,"%s",input);
    //obtem nome do primeiro idoso
    atual = strtok(input,";");
    while(atual){
        //percorre os idosos da rede, criando a lista que os contém
        insereIdoso(idosos,atual);
        atual = strtok(NULL,";");
    }

    imprimeListaIdosos(idosos);
    printf("\n");

    //percorrer as amizades!
    while(!feof(arqApoio)){
        //criar a lista de amigos de cada idoso!
        fscanf(arqApoio,"%s", input);
        atual = strtok(input,";");
        while(atual){
            prox = strtok(NULL,";");//obtém o segundo integrante da dupla
            printf("%s e %s", atual,prox);
            //faz a amizade entre os dois idosos!
            

            atual = strtok(NULL,";");//vai para a proxima dupla
        }
        printf("\n");
        fscanf(arqApoio,"\n");
    }
    fclose(arqApoio);//finaliza o uso do arquivo de apoio -> TA DANDO ERRO?
    
    //os idosos estão criados, as listas de amigos também!
    //falta criar a lista mestre de cuidadores e as listas de cuidadores de cada idoso
    //verifica se o arquivo foi aberto com sucesso
    FILE* arqCuidadores = fopen(entradas"/cuidadores.txt", "r");
    if(!arqCuidadores) return 1;

    //obtem nome do primeiro cuidador
    fscanf(arqCuidadores,"%s",input);
    atual = strtok(input,";");

    while(atual){
        //percorre os cuidadores da rede, criando a lista que os contém
        insereCuidador(cuidadores,atual);
        atual = strtok(NULL,";");
    }
    imprimeListaCuidador(cuidadores);
    printf("\n");

    while(!feof(arqCuidadores)){
        fscanf(arqCuidadores,"%s", input);
        atual = strtok(input,";");//obtem o idoso alvo
        prox = strtok(NULL,";");//obtem o primeiro cuidador
        while(prox){
            printf("%s: %s",atual,prox);
            //adicionar o cuidador alvo à lista de cuidadores do idoso alvo



            prox = strtok(NULL,";");
        }
        fscanf(arqCuidadores,"\n");
        printf("\n");
    }
    fclose(arqCuidadores);//finaliza o uso do arquivo de apoio
    destroiListaCuidador(cuidadores);
    destroiListaIdoso(idosos);
    return 0;
}