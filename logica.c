#include "logica.h"
#include "dados.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int valida_jogada(ESTADO *e, COORDENADA c){
    int x1 = e->ultima_jogada.x, y1 = e->ultima_jogada.y;
    int x2 = c.x, y2 = c.y;
    if (c.x>7 || c.x<0 || c.y>7 || c.y<0) return 2;

    if(((x1 == x2) && (((abs(y1-y2))==1))) || (((abs(x2-x1))==1) && ((abs(y2-y1))==1 || y2 == y1 ))){
        CASA casa_coord = obter_estado_casa(e,c);
        if(casa_coord == VAZIO) return 1;
    }
    return 0;
}

int jogar(ESTADO *e, COORDENADA c) {
    if(valida_jogada(e,c)){
        alterar_casa(e,c);
        alterar_ultima_jogada(e,c);
        alterar_jogador_atual(e);
        //e->jogadas[obter_numero_de_jogadas(e)] = c;
        alterar_num_jogadas(e);
        return 1;
    }
    else return 0;
}
