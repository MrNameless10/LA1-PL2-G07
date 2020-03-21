
#include "camada de dados.h"
#include "logica de programa.h"
#include <stdlib.h>
#include <stdio.h>

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int x,y;
    for(y=0;y<8;y++) {
        for (x=0; x<8; x++) {
            e->tab[x][y] = VAZIO;
        }
    }

    e->ultima_jogada.x = 4;
    e->ultima_jogada.y = 3;
    e->tab[4][3] = BRANCA; //posicao da peca branca no inicio do jogo
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    e->num_comandos = 0;
    //e->jogadas

    return e;
}

int obter_jogador_atual(ESTADO *e) {
    return e->jogador_atual;
}

//int obter_numero_de_jogadas(ESTADO *estado){
int obter_numero_de_jogadas(ESTADO *e) {
    return e->num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    return e->tab[c.x][c.y];
}

CASA obter_casa(ESTADO *e,int x,int y){
    return e->tab[x][y];
}

COORDENADA obter_ultima_jogada(ESTADO *e){
    return e->ultima_jogada;
}

void alterar_casa(ESTADO *e, COORDENADA c)
{
    int x = obter_ultima_jogada(e).x;
    int y = obter_ultima_jogada(e).y;

    e -> tab[x][y] = PRETA;
    e -> tab[c.x][c.y] = BRANCA;
}

void alterar_ultima_jogada(ESTADO *e, COORDENADA c) {
    e->ultima_jogada.x = c.x;
    e->ultima_jogada.y = c.y;
}

int add_comando(ESTADO *e) {
    return e->num_comandos += 1;
}

void mostrar_prompt(ESTADO *e){
    printf("# %d  PL%d  (%d)>", add_comando(e), obter_jogador_atual(e),obter_numero_de_jogadas(e));
}

void alterar_jogador_atual(ESTADO *e){
    if(obter_jogador_atual (e) == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}

int fim_de_jogo(ESTADO *e, COORDENADA c) {
    COORDENADA cor;
    if (c.y == 0 && c.x == 7) return 2;
    if (c.y == 7 && c.x == 0) return 1;
    for (int i = c.y - 1; i <= c.y + 1; i++) {
        for (int k = c.x - 1; k <= c.x + 1; k++) {
            cor.x = i;
            cor.y = k;
            if (valida_jogada(e, cor)==0) return 0;
        }
    }
    return (obter_jogador_atual(e)== 1 ? 2 : 1) ;
}

void alterar_num_jogadas(ESTADO *e){
    if (obter_jogador_atual(e)== 1)
        e->num_jogadas++;
}


