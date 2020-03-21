#include "logica de programa.h"
#include "camada de dados.h"
#include <math.h>
#include <stdio.h>

int valida_jogada(ESTADO*e, COORDENADA c){
    int c1,l1,c2,l2;
    c1 = obter_ultima_jogada(e).x;
    l1 = obter_ultima_jogada(e).y;
    c2 = c.x;
    l2 = c.y;

    if((sqrt((c1-c2)^2-(l1-l2)^2) == 1) && e->tab[c.x][c.y] == VAZIO) return 1;
    else return 0;

    //int x = e->ultima_jogada.x;
    //int y = e->ultima_jogada.y;


    //int r = 0;
    //if (e->tab[c.x][c.y] == VAZIO && c.x >= x - 1 && c.x <= x + 1 && c.y >= y - 1 && c.y <= y + 1)
        //r = 1;
    //return r;

}

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.x, c.y);
    if(valida_jogada(e,c)){
        alterar_casa(e,c);
        alterar_ultima_jogada(e,c);
        alterar_jogador_atual(e);
        //e->jogadas[obter_numero_de_jogadas(e)] = c;
        if(fim_de_jogo(e,c)) printf("GAME OVER! Parabéns jogador %d",obter_jogador_atual(e));
        return 1;
    }
    else return 0;
}
