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
\brief Verifica se o jogo acabou @param e aponta para o estado @param c COORDENADA da ultima jogada @returns Jogador vencedor
*/
int fim_de_jogo(ESTADO *e, COORDENADA c);

/**
\brief Calcula a distância @param c1 Coordenada @param c2 Coordenada
*/
float distancia_euclidiana(COORDENADA c1 ,COORDENADA c2);

/**
\brief  Joga, atualizando os valores do estado do tabuleiro @param e aponta para o estado @param c COORDENADA da jogada a ser efetuada
*/
int jogar(ESTADO *e, COORDENADA c);

#endif //UNTITLED_LOGICA_DE_PROGRAMA_H
