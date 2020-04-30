/**
@file interface.h
Definições das funções que fazem a ligação ao jogador
*/
#include "dados.h"
#include <stdio.h>

/**
\brief Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Recebe o input do jogador @param e aponta para o estado do jogo
*/
int interpretador(ESTADO *e);

/**
\brief Lê um ficheiro @param ficheiro ficheiro a ser lido @param e aponta para o estado do jogo
*/
void ler(char *ficheiro, ESTADO *e);

/**
\brief Grava um ficheiro @param ficheiro ficheiro a ser gravado @param e aponta para o estado do jogo
*/
void gr(char *ficheiro, ESTADO *e);

/**
\brief Imprime o prompt @param e aponta para o estado do jogo
*/
void mostrar_prompt(ESTADO *e);

/**
\brief Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo @param jogo guarda o jogo no File para o output
*/
void escreve_tabuleiro(ESTADO *e, FILE *jogo);

/**
\brief Função que mostra os movimentos @param jogo file onde guarda os movimentos @param e aponta para o estado do jogo
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
\brief Função que congratula o jogador correspondente @param e aponta para o estado @param c coordenada da ultima jogada
*/
void congratular_jogador(ESTADO *e, COORDENADA c);