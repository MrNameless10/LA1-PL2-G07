ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int x,y;
    for(y=8;y>=1;y--) {
        for (x = 1; x <= 8; x++) {
            e->tab[x][y] = VAZIO;
        }
    }
    e->ultima_jogada.x = 5;
    e->ultima_jogada.y = 5;
    e->tab[5][5] = BRANCA;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    //e->jogadas
    
    return e;
}
//int obter_jogador_atual(ESTADO *estado){

//int obter_numero_de_jogadas(ESTADO *estado){

//CASA obter_estado_casa(ESTADO *e, COORDENADA c){
