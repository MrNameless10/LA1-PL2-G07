/**
@file logica.h
Definições das funções que representam a jogabilidade do jogo
*/
#ifndef UNTITLED_LOGICA_DE_PROGRAMA_H
#define UNTITLED_LOGICA_DE_PROGRAMA_H

#include "dados.h"

/**
\brief Verifica se a jogada é valida @param e aponta para o estado do jogo @param c Coordenada da jogada @returns 1 se Jogada Válida e \n 0 ou 2 se Jogada Inválida
*/
int valida_jogada(ESTADO*e, COORDENADA c);

/**
\brief  Joga, atualizando os valores do estado do tabuleiro @param e aponta para o estado @param c COORDENADA da jogada a ser efetuada
*/
int jogar(ESTADO *e, COORDENADA c);


#endif //UNTITLED_LOGICA_DE_PROGRAMA_H
