#ifndef UNTITLED_CAMADA_DE_DADOS_H
#define UNTITLED_CAMADA_DE_DADOS_H
//#include <stdio.h>
#include "listas.h"

typedef enum {VAZIO, BRANCA, PRETA} CASA;

typedef struct {
    int x;
    int y;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
    int num_comandos;
} ESTADO;

ESTADO *inicializar_estado();
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
CASA obter_casa(ESTADO *e,int x,int y);
COORDENADA obter_ultima_jogada(ESTADO *e);
void alterar_casa(ESTADO *e, COORDENADA c);
void alterar_ultima_jogada(ESTADO *e, COORDENADA c);
int add_comando(ESTADO *e);
void alterar_jogador_atual(ESTADO *e);
int fim_de_jogo(ESTADO *e, COORDENADA c);
void alterar_num_jogadas(ESTADO *e);
void alterar_jogadas(ESTADO *e, COORDENADA c);
int bloqueado (ESTADO *e, COORDENADA c);
int obter_num_comandos (ESTADO *e);
void jogadas_anteriores_guardadas(ESTADO *e, char c, int n);
int jogadas_guardadas(ESTADO *e, int i, int j);
char* str_jogada_guardada(ESTADO *e, int i, int j);
void lelinha(char const *linha, int nlinha, ESTADO *e);
//ESTADO *novo_estado(FILE *);
void reset_estado(ESTADO *e);
void posicao(int num, ESTADO *e);
void decrementa_ncomandos(ESTADO *e);
LISTA posicoes_possiveis(ESTADO *e, LISTA l);
float distancia_euclidiana(COORDENADA c1 ,COORDENADA c2);
int tamanho_lista(LISTA l);

#endif //UNTITLED_CAMADA_DE_DADOS_H
