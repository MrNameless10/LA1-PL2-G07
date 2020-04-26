/**
@file interface.h
Definições das funções que fazem a ligação ao jogador
*/
#include "dados.h"

/**
\brief Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Recebe o input do jogador @param e aponta para o estado do jogo
*/
int interpretador(ESTADO *e);

//void q ();
/**
\brief Lê um ficheiro @param ficheiro @param e aponta para o Estado do jogo
*/
void ler(char *ficheiro, ESTADO *e);

/**
\brief Grava um ficheiro @param ficheiro @param e aponta para o Estado do jogo
*/
void gr(char *ficheiro, ESTADO *e);

/**
\brief Imprime o prompt @param e aponta para o estado do jogo
*/
void mostrar_prompt(ESTADO *e);

/**
\brief Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo @param guarda o jogo no File para o output
*/
void escreve_tabuleiro(ESTADO *e, FILE *jogo);

/**
\brief Função que mostra os movimentos @param jogo @param e aponta para o estado do jogo
*/
void movs(FILE *jogo, ESTADO *e);

/**
\brief Função que joga pelo jogador pela estrategia da distancia euclidian @param e aponta para o estado do jogo
*/
void jog(ESTADO *e);

/**
\brief Função que joga pelo jogador pela estrategia baseada na paridade @param e aponta para o estado do jogo
*/
void jog2(ESTADO *e);

/**
\brief Função que congratula o jogador correspondente @param e aponta para o estado @param COORDENADA da ultima jogada
*/
void congratular_jogador(ESTADO *e, COORDENADA c);