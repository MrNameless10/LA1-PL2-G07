/**
@file logica.h
Definições das funções que representam a jogabilidade do jogo
*/
#ifndef UNTITLED_LOGICA_DE_PROGRAMA_H
#define UNTITLED_LOGICA_DE_PROGRAMA_H

#include "dados.h"

/**
\brief Recebe uma coordenada jogando quando é válida @param e aponta para o estado do jogo @param c Coordenada da jogada dando @returns 1 se Jogada Válida e \n 0 se Jogada Inválida
*/
int valida_jogada(ESTADO*e, COORDENADA c);

/**
\brief Determina se o jogo foi ganho @param e aponta para o estado do jogo @param c Coordenada da última jogada dando @returns 0 se o Jogo não acabou, \n 1 se há Vitória do jogador 1 e \n 2 se há Vitória do jogador 2
*/
int jogar(ESTADO *e, COORDENADA c);


#endif //UNTITLED_LOGICA_DE_PROGRAMA_H
