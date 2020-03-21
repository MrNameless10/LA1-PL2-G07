#include "camada_de_dados.h"
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
}

int fim_de_jogo(ESTADO *e, COORDENADA c) {
    COORDENADA co;
    for (int i = c.y - 1; i <= c.y + 1; i++) {
        for (int k = c.x - 1; k <= c.x + 1; k++) {
            co.x = i;
            co.y = k;
            if (valida_jogada(e, co)==1) return 0;
        }
    }
    return obter_jogador_atual(e) ;
}
        
int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.x, c.y);
    if(valida_jogada(e,c)){
	    alterar_casa (e,c);
	    alterar_ultima_jogada(e,c);
	    alterar_jogador_atual(e);
	    //e->jogadas[obter_numero_de_jogadas(e)] = c;
	    if(fim_de_jogo(e,c)) printf("GAME OVER! Parabéns jogador %d", obter_jogador_atual(e));
        return 1;
    }
    else return 0;    
}
