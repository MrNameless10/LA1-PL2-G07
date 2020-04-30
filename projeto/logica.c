#include "dados.h"
#include <stdlib.h>
#include <math.h>

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

int fim_de_jogo(ESTADO *e, COORDENADA c) {
    COORDENADA cor;
    if (c.y == 7 && c.x == 7) return 2;
    if (c.y == 0 && c.x == 0) return 1;
    if (bloqueado(e,c)==8) return (obter_jogador_atual(e)== 1 ? 2 : 1);
    for (int i = c.y - 1; i <= c.y + 1; i++) {
        for (int k = c.x - 1; k <= c.x + 1; k++) {
            cor.x = i;
            cor.y = k;
            if (valida_jogada(e, cor)==0) return 0;
        }
    }
    return (obter_jogador_atual(e)== 1 ? 2 : 1);
}

float distancia_euclidiana(COORDENADA c1 ,COORDENADA c2){

    float d = sqrtf(pow(c1.y - c2.y, 2) + pow(c1.x - c2.x, 2));
    return d;
}

int jogar(ESTADO *e, COORDENADA c) {
    if(valida_jogada(e,c)){
        alterar_casa(e,c);
        alterar_ultima_jogada(e,c);
        alterar_jogadas(e, c);
        alterar_jogador_atual(e);
        alterar_num_jogadas(e);
        return 1;
    }
    else return 0;
}
