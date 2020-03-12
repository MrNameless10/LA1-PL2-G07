// Função que deve ser completada e colocada na camada da lógica do programa
int ver_movimentos(ESTADO*e, COORDENADA c){
    int c1,l1,c2,l2;
    c1 = e-> ultima_jogada.x;
    l1 = e-> ultima_jogada.y;
    c2 = c.x;
    l2 = c.y;
    
    if((sqrt((c1-c2)^2-(l1-l2)^2) == 1
        return 1;
}
        
int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    if(ver_movimentos(e,c)){
     e-> tab[c.x][c.y] = BRANCA;
     e-> tab[ultima_jogada.x][ultima_jogada.y] = PRETA;
        return 1;}
    else return 0;    
}

int jogar(ESTADO *e, COORDENADA c){
    
    e->tab[ultima_jogada.x][ultima_jogada.y] = PRETA;
	e->tab[c.x][c.y] = BRANCA;
    e->ultima_jogada.x = c.x;
    e->ultima_jogada.y = c.y;	
    e->jogador_atual = obter_jogador_atual (e);
    e->jogadas[e->obter_numero_de_jogadas(e)] = c;
}

