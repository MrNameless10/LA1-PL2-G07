#include <stdlib.h>

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int x,y;
    for(y=0;y<8;y++) {
        for (x=0; x<8; x++) {
            e->tab[x][y] = VAZIO;
        }
    }
      
    e->ultima_jogada.linha = 4;
    e->ultima_jogada.coluna = 3; 
    e->tab[4][3] = BRANCA; //posicao da peca branca no inicio do jogo
    e->num_jogadas = 0; 
    e->jogador_atual = 1;
    //e->jogadas

    return e;
}
//int obter_jogador_atual(ESTADO *estado){

int obter_jogador_atual(ESTADO *e) {
    //int jogador;
    //if (e->num_jogadas % 2 == 0) jogador = 1;
    //else jogador = 2;
    //return jogador;
    return e->jogador_atual;
}

//int obter_numero_de_jogadas(ESTADO *estado){
int obter_numero_de_jogadas(ESTADO *e) {
    //int x= e->num_jogadas;
    //x=x+1;
    //e->num_jogadas = x;
return e->num_jogadas;
}

//CASA obter_estado_casa(ESTADO *e, COORDENADA c){
CASA obter_estado_casa(ESTADO *e, COORDENADA c){
return e->tab[c.linha][c.coluna];
}
