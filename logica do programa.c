
#include "camada de dados.h"
#include <math.h>
#include <stdio.h>

int ver_movimentos(ESTADO*e, COORDENADA c){
    int c1,l1,c2,l2;
    c1 = e-> ultima_jogada.linha;
    l1 = e-> ultima_jogada.coluna;
    c2 = c.linha;
    l2 = c.coluna;
    
    if((sqrt((c1-c2)^2-(l1-l2)^2) == 1
        return 1;
}
        
int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    if(ver_movimentos(e,c)){
	    e->tab[ultima_jogada.x][ultima_jogada.y] = PRETA;
	    e->tab[c.linha][c.coluna] = BRANCA;
	    e->ultima_jogada.linha = c.linha;
	    e->ultima_jogada.coluna = c.coluna;	
	    e->jogador_atual = obter_jogador_atual (e);
	    e->jogadas[e->obter_numero_de_jogadas(e)] = c;
        return 1;}
    else return 0;    
}
