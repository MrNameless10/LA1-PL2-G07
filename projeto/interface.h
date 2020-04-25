/**
@file interface.h
Definições das funções que fazem a ligação ao jogador
*/
#include "dados.h"

/**
\Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\Recebe o input do jogador @param e aponta para o estado do jogo
*/
int interpretador(ESTADO *e);

//void q ();
/**
/Lê um ficheiro @param ficheiro @param e aponta para o Estado do jogo
*/
void ler(char *ficheiro, ESTADO *e);

/**
/Grava um ficheiro @param ficheiro @param e aponta para o Estado do jogo
*/
void gr(char *ficheiro, ESTADO *e);

/**
\Imprime o prompt @param e aponta para o estado do jogo
*/
void mostrar_prompt(ESTADO *e);

/**
\Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo @param jogo File para o output
*/
void escreve_tabuleiro(ESTADO *e, FILE *jogo);
