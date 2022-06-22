#ifndef LOCAL_H
#define LOCAL_H

//define o tipo opaco Localizacao
typedef struct local Localizacao;

/*
    inicializa um novo local
    Pré-condição: nenhuma
    Pós-condição: local criado
*/
Localizacao* inicLocal(float latitude, float longitude);

/*
    Dados dois locais, calcula a distância entre eles
    Pré-condição: os dois locais existem
    Pós-condição: distancia calculada
*/
float calculaDistancia(Localizacao* prim, Localizacao* seg);

/*
    Dado um local, obtem a latitude dele
    Pré-condição: o local existe
    Pós-condição: latitude retornada
*/
float retornaLatitude(Localizacao* local);

/*
    Dado um local, obtem a longitude dele
    Pré-condição: o local existe
    Pós-condição: longitude retornada
*/
float retornaLongitude(Localizacao* local);

/*
    Dado um local, muda a latitude e a longitude dele
    Pré-condição: o local existe
    Pós-condição: local atualizado
*/
void atualizaLocalizacao(Localizacao* local,float latitude, float longitude);

/*
    Dado um local, libera a memória dele
    Pré-condição: o local existe
    Pós-condição: toda a memória foi liberada
*/
void destroiLocal(Localizacao* local);

#endif