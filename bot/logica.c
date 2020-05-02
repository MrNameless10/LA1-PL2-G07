#include "dados.h"
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
}

/*void jog2(ESTADO *e) { //contém a Estratégia baseada na paridade!!!
    int d= INT_MAX;
    COORDENADA c,target, *a, *b;
    LISTA l = criar_lista();
    LISTA j= criar_lista();
    c.x = 0;
    c.y = 0;
    l = posicoes_possiveis(e, l);

    if(obter_jogador_atual(e)==1){
        target.x = 0;
        target.y = 0;
    }
    else{
        target.x = 7;
        target.y = 7;
    }
    while (lista_esta_vazia(l)==0) {
        a = devolve_cabeca(l);
        c = *a;
        insere_cabeca(j,a);
        proximo(j);
        l = proximo(l);
    }
    while((bloqueado(e,c) % 2 != 0) && (distancia_euclidiana(*a, target) > d)){
        d = distancia_euclidiana(*a, target);
        proximo(j);
        b = devolve_cabeca(j);
        c = *b;
    }

    jogar(e,c);
    congratular_jogador(e,c);
}*/