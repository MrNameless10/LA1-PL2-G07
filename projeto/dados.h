#ifndef UNTITLED_CAMADA_DE_DADOS_H
#define UNTITLED_CAMADA_DE_DADOS_H
//#include <stdio.h>
#include "listas.h"

/**
@file dados.h
Definições do estado e da manipulação deste através das funções
*/
typedef enum {VAZIO, BRANCA, PRETA} CASA;

/**
\brief Tipos de dados para as respetivas coordenadas
*/
typedef struct {
    int x;
    int y;
} COORDENADA;

/**
\brief Tipos de dados para a respetiva jogada
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Tipos de dados para as respetivas jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipos de dados para para o estado
*/
typedef struct {
    /** Tabuleiro */
    CASA tab[8][8];
    /** Ultima Jogada */
    COORDENADA ultima_jogada;
    /** Jogadas */
    JOGADAS jogadas;
    /** Numero de jogadas */
    int num_jogadas;
    /** Jogador Atual */
    int jogador_atual;
    /** Numero de comandos */
    int num_comandos;
} ESTADO;

/**
\brief Inicializa o valor do respetivo estado dando o @returns do Novo estado
*/
ESTADO *inicializar_estado();

/**
\brief Obtém o jogador atual @param e aponta para o estado dando o @returns do Jogador atual
*/
int obter_jogador_atual(ESTADO *estado);

/**
\brief Obtém o número de jogadas @param e aponta para o estado dando o @returns do número de jogadas
*/
int obter_numero_de_jogadas(ESTADO *estado);

/**
\brief Verifica se está livre uma certa casa @param e aponta para o estado @param c Coordenada dando @returns 0 se a casa não pode ser jogada e \n 1 se a casa pode ser jogada
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);

/**
\brief Devolve o valor da casa @param e aponta para o estado @param x Linha da jogada @param y Coluna da jogada dando o @returns Valor da casa
*/
CASA obter_casa(ESTADO *e,int x,int y);

/**
\brief Devolve a última jogada @param e aponta para o estado do jogo @returns Coordenada da última jogada
*/
COORDENADA obter_ultima_jogada(ESTADO *e);

/**
\brief Muda o valor de uma casa @param e aponta para o estado @param c Coordenada
*/
void alterar_casa(ESTADO *e, COORDENADA c);

/**
\brief Altera o valor do comando @param e aponta para o estado
*/
void alterar_ultima_jogada(ESTADO *e, COORDENADA c);

/**
\brief Aumenta o valor do comando @param e aponta para o estado
*/
int add_comando(ESTADO *e);

/**
\brief Muda o jogador @param e aponta para o estado
*/
void alterar_jogador_atual(ESTADO *e);

/**
\brief Altera o jogador @param e aponta para o estado
*/
int fim_de_jogo(ESTADO *e, COORDENADA c);

/**
\brief Termina o valor do comando @param e aponta para o estado
*/
void alterar_num_jogadas(ESTADO *e);

/**
\brief Altera o número da jogada atual @param e aponta para o estado do jogo @param num_mov numero do movimento para onde se altera a jogada atual
*/
void alterar_jogadas(ESTADO *e, COORDENADA c);

/**
\brief Vê as casa ocupadas @param c COORDENADA dando @returns do número de casas ocupados
*/
int bloqueado (ESTADO *e, COORDENADA c);

/**
\brief Adiciona 1 ao número de comandos @param e aponta para o estado do jogo
*/
int obter_num_comandos (ESTADO *e);

/**
\brief Recebe a jogada a ler @param e aponta para o estado do jogo @param c coluna @param n linha
*/
void jogadas_anteriores_guardadas(ESTADO *e, char c, int n);

/**
\brief Retorna coordenadas @param e aponta para o estado do jogo @param i Número da jogada @param j Jogador atual dando @returns 0 se a Jogada não existe e \n 1 se a Jogada existe
*/
int jogadas_guardadas(ESTADO *e, int i, int j);

/**
\brief Retorna a jogada a imprimir @param e aponta para o estado do jogo @param i Número da jogada @param j Jogador atual dando o @returns String com a jogada
 */
char* str_jogada_guardada(ESTADO *e, int i, int j);

/**
\brief Lê uma linha e guarda no estado de jogo @param Linha @param numlinha Index da linha @param e aponta para o estado do jogo
*/
void lelinha(char const *linha, int nlinha, ESTADO *e);

//ESTADO *novo_estado(FILE *);
/**
\brief Dá reset ao tabuleiro @param e aponta para o estado do jogo
*/
void reset_estado(ESTADO *e);

/**
\brief Altera número da jogada atual @param e aponta para o estado do jogo @param num_mov numero do movimento onde altera a jogada atual
*/
void posicao(int num, ESTADO *e);

/**
\brief Verifica o número de jogadas @param e aponta para o estado de jogo
*/
void decrementa_ncomandos(ESTADO *e);

/**
\brief Vê as jogadas possiveis @param e aponta para o estado de jogo @param l uma lista
*/
LISTA posicoes_possiveis(ESTADO *e, LISTA l);

/**
\brief Calcula a distância @param c1 Coordenada @param c2 Coordenada
*/
float distancia_euclidiana(COORDENADA c1 ,COORDENADA c2);

#endif //UNTITLED_CAMADA_DE_DADOS_H
