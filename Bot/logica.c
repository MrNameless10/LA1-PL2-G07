//
// Created by miguel on 28/04/2020.
//
#include "dados.h"
#include "interface.h"
#include <stdlib.h>
#include <limits.h>


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

void jog(ESTADO *e){  //contém a estrategia da distancia Euclidiana!!!
    int d = INT_MAX;
    COORDENADA c, target, *a;
    LISTA l = criar_lista();
    l = posicoes_possiveis(e,l);
    LISTA m = l;
    c.x=0;
    c.y=0;

    if(obter_jogador_atual(e)==1){
        target.x = 0;
        target.y = 0;
    }
    else{
        target.x = 7;
        target.y = 7;
    }

    while(lista_esta_vazia(m)==0){
        a = devolve_cabeca(m);

        if(distancia_euclidiana(*a, target) < d){
            d = distancia_euclidiana(*a, target);
            c = *a;
        }
        m = proximo(m);
    }
    jogar(e,c);
    congratular_jogador(e,c);
}