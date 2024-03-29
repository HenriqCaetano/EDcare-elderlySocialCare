#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _GNU_SOURCE
#include "local.h"
#include "idoso.h"
#include "listaIdoso.h"
#include "listaCuidador.h"

#define input "./Testes/Testes/Teste6/Entrada/"
#define output "./Testes/Testes/Teste6/"

struct idoso
{
    char* nome;
    float temperatura;
    int queda;
    int contaFebre;
    int morte;
    Localizacao* local;
    ListCuidador* cuidadores;
    ListIdoso* amigos;
    FILE* arqEnt;
    FILE* arqSaida;
};

Idoso* inicIdoso(char* nome){
    
    Idoso* idoso = (Idoso*) malloc(sizeof(Idoso));

    idoso->nome = strdup(nome);
    idoso->temperatura= 0;
    idoso->queda = 0;
    idoso->contaFebre = 0;
    idoso->morte=0;
    idoso->local = inicLocal(0, 0);

    idoso->cuidadores = inicListaCuidador();
    idoso->amigos = inicListaIdoso();

    char in[500], out[500];

    sprintf(in,"%s%s.txt",input,nome);
    sprintf(out,"%s%s-saida.txt",output,nome);

    idoso->arqEnt = fopen(in,"r");
    idoso->arqSaida = fopen(out,"w");

    sprintf(in," ");
    sprintf(out," ");

    return idoso;
}

void atualizaIdoso(Idoso* idoso){
    if(!idoso) return;
    //se o idoso estiver morto, não faz nada.
    if(idoso->morte) return;

    char* dado;
    char entrada[500];
    float lat,lon;
    fscanf(idoso->arqEnt,"%s",entrada);
    //verifica se idoso morreu
    if(strcmp(entrada,"falecimento") == 0){
        //chamar função para matar o idoso
        
        faleceIdoso(idoso);
        fprintf(idoso->arqSaida,"falecimento\n");//como pode isso dar erro?
        return;
    }
    
    //se está vivo, lê as entradas sensoriadas
    dado = strtok(entrada,";");
    idoso->temperatura = atof(dado);

    dado = strtok(NULL,";"); //obtem a latitude
    lat = atof(dado);
    dado = strtok(NULL,";"); //obtem a longitude
    lon = atof(dado);
    atualizaLocalizacao(idoso->local,lat,lon);

    dado = strtok(NULL,";");//obtem o verificador de queda
    idoso->queda = atoi(dado);

    return;
}

void processaDadosIdoso(Idoso* idoso){
    if(!idoso) return;
    if(idoso->morte) return; //se idoso estiver morto, não faz nada

    //verifica se o idoso caiu: chama cuidador
    if(idoso->queda){
        //verificar se houve febre baixa para atualizar o contador
        if(idoso->temperatura > 37 && idoso->temperatura < 38){
            idoso->contaFebre++;
            if(idoso->contaFebre >= 4) idoso->contaFebre = 0;
        }
        //chamar o cuidador mais proximo!
        fprintf(idoso->arqSaida,"queda, acionou %s\n", obtemCuidadorMaisProximo(idoso->cuidadores, idoso));
        return;
    }
    //verifica se o idoso está com febre alta: chama cuidador
    else if(idoso->temperatura >= 38){
        //chama o cuidador mais próximo
        fprintf(idoso->arqSaida,"febre alta, acionou %s\n", obtemCuidadorMaisProximo(idoso->cuidadores,idoso));
        return;
    }

    //verifica se o idoso está com febre baixa: chama amigo(exceto na quarta vez)
    else if(idoso->temperatura >= 37){
        idoso->contaFebre++;
        if(idoso->contaFebre >= 4){
            //chama o cuidador mais proximo
            fprintf(idoso->arqSaida,"febre baixa pela quarta vez, acionou %s\n", obtemCuidadorMaisProximo(idoso->cuidadores, idoso));
            idoso->contaFebre = 0;
        }
        else {
            if(verificaListaVazia(idoso->amigos)){
                fprintf(idoso->arqSaida,"Febre baixa mas, infelizmente, o idoso está sem amigos na rede\n");
                return;
            }
            fprintf(idoso->arqSaida,"febre baixa, acionou amigo %s\n",obtemAmigoMaisProximo(idoso->amigos,idoso));
        }
        return;
    }
    //no caso comum, o idoso está bem
    fprintf(idoso->arqSaida,"tudo ok\n");
}

void imprimeIdoso(Idoso* idoso){
    if(!idoso) return;
    printf("NOME: %s\n", idoso->nome);
}

ListIdoso* obtemAmigosIdoso(Idoso* idoso){
    if(!idoso) exit(1);
    return idoso->amigos;
}

ListCuidador* obtemCuidadoresIdoso(Idoso* idoso){
    if(!idoso) exit(1);
    return idoso->cuidadores;
}


char* retornaNomeIdoso(Idoso* idoso){
    if(!idoso) exit(1);
    return idoso->nome;
}

Localizacao* retornaLocalIdoso(Idoso* idoso){
    if(!idoso) exit(1);
    return idoso->local;
}

void destroi_Idoso(Idoso* idoso){
    if(idoso != NULL){
        destroiLocal(idoso->local);
        destroiListaCuidador(idoso->cuidadores);
        destroiListaIdoso(idoso->amigos);
        free(idoso->nome);

        fclose(idoso->arqEnt);
        fclose(idoso->arqSaida);

        free(idoso);
    }
}   
void faleceIdoso(Idoso* idoso){
    if(!idoso) return;
    //torna o idoso morto
    idoso->morte = 1;
    //função que recebe a lista de amigos, acessa cada lista de amigos de cada amigo e retira o idoso morto
    desfazAmizades(idoso->amigos,idoso->nome);
}