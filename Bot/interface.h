//
// Created by miguel on 28/04/2020.
//

#ifndef BOT_INTERFACE_H
#define BOT_INTERFACE_H
#include <stdio.h>

/**
\brief Imprime o prompt @param e aponta para o estado do jogo
*/
void mostrar_prompt(ESTADO *e);

/**
\brief Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Lê um ficheiro @param ficheiro @param e aponta para o Estado do jogo
*/
void ler(char *ficheiro, ESTADO *e);

/**
\brief Grava um ficheiro @param ficheiro @param e aponta para o Estado do jogo
*/
void gr(char *ficheiro, ESTADO *e);

/**
\brief Função que mostra os movimentos @param jogo @param e aponta para o estado do jogo
*/
void movs(FILE *jogo, ESTADO *e);

/**
\brief Mostra o tabuleiro na linha de comandos @param e aponta para o estado do jogo @param guarda o jogo no File para o output
*/
void escreve_tabuleiro(ESTADO *e, FILE *jogo);

/**
\brief Função que congratula o jogador correspondente @param e aponta para o estado @param COORDENADA da ultima jogada
*/
void congratular_jogador(ESTADO *e, COORDENADA c);

#endif //BOT_INTERFACE_H
