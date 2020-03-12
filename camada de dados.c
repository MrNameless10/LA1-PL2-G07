ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int x,y;
    for(y=8;y>=1;y--){
        for(x=1;x<=8;x++){
            e->tab[x][y] = VAZIO;
        }
    }
    e->tab[5][5] = BRANCA;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    //e->ultima_jogada
    //e->jogadas

    return e;
}
