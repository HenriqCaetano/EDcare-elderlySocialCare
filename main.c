#include "idoso.h"
#include "cuidador.h"
#include "listaCuidador.h"
#include "listaIdoso.h"
#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>

#define entradas "./Testes/Testes/Teste2/Entradas"


int main(int argc, char* argv[]){
    if(argc == 1){
        printf("Necessário número de entradas sensoriadas!\n");
        return 1;
    }

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
        insereElemento(idosos,atual);
        atual = strtok(NULL,";");
    }

    //percorrer as amizades!
    while(!feof(arqApoio)){
        //criar a lista de amigos de cada idoso!
        fscanf(arqApoio,"%s", input);
        atual = strtok(input,";");
        while(atual){
            prox = strtok(NULL,";");//obtém o segundo integrante da dupla
            //faz a amizade entre os dois idosos!
            cria_AmizadeIdosos(idosos,atual,prox);
            atual = strtok(NULL,";");//vai para a proxima dupla
        }
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
        insere_ElementoCuidador(cuidadores,atual);
        atual = strtok(NULL,";");
    }
    
    Idoso* idosoAlvo;
    Cuidador* cuidadorAlvo;
    while(!feof(arqCuidadores)){
        fscanf(arqCuidadores,"%s", input);
        atual = strtok(input,";");//obtem o idoso alvo
        prox = strtok(NULL,";");//obtem o primeiro cuidador
        idosoAlvo = buscaIdoso(idosos,atual);
        while(prox){
            //adicionar o cuidador alvo à lista de cuidadores do idoso alvo
            cuidadorAlvo = buscaCuidador(cuidadores,prox);
            insereCuidador(obtemCuidadoresIdoso(idosoAlvo),cuidadorAlvo);
            prox = strtok(NULL,";");
        }
        fscanf(arqCuidadores,"\n");
    }
    fclose(arqCuidadores);//finaliza o uso do arquivo de apoio

    
    //neste momento, a rede está configurada e pronta para as entradas sensoriadas!

    int i, sensoriadas;
    sensoriadas = atoi(argv[1]);
    //ciclo de leituras!
    for(i=0; i<sensoriadas; i++){

        //VERIFICAR SE OS DADOS OBTIDOS FORAM COMPATÍVEIS!!
        //atualiza todos os idosos da lista mestre de idosos
        atualizaDadosListaIdoso(idosos);

        //atualiza todos os cuidadores da lista mestre de cuidadores
        atualizaDadosListaCuidador(cuidadores);

        //função para processar e escrever saídas - recebe a lista mestre de idosos!
        processaDadosListaIdoso(idosos);
    }

    


    //destroiListaCuidador(cuidadores);
    //destroiListaIdoso(idosos);
    return 0;
}