//
// Created by miguel on 28/04/2020.
//

#ifndef BOT_LOGICA_H
#define BOT_LOGICA_H

/**
\brief Verifica se a jogada é valida @param e aponta para o estado do jogo @param c Coordenada da jogada @returns 1 se Jogada Válida e \n 0 ou 2 se Jogada Inválida
*/
int valida_jogada(ESTADO*e, COORDENADA c);

/**
\brief Verifica se o jogo acabou @param e aponta para o estado @param c COORDENADA da ultima jogada @returns Jogador vencedor
*/
int fim_de_jogo(ESTADO *e, COORDENADA c);

/**
\brief  Joga, atualizando os valores do estado do tabuleiro @param e aponta para o estado @param c COORDENADA da jogada a ser efetuada
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que joga pelo jogador pela estrategia da distancia euclidian @param e aponta para o estado do jogo
*/
void jog(ESTADO *e);


#endif //BOT_LOGICA_H
