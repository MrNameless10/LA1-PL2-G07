void mostrar_tabuleiro(ESTADO *e) {
    int x ,y;

    for(y=8;y>=1; y--){
        for(x=1;x<=8;x++){
            if(x==8 && y==8) printf("2");
            else if (x==1 && y==1) printf("1");
            else if (e->tab[x][y]==BRANCA) printf("*");
            else if (e->tab[x][y]==VAZIO) printf(".");
            else if (e->tab[x][y]==PRETA) printf("#");
        }
        printf("\n");
    }
}


// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
char linha[BUF_SIZE];
char col[2], lin[2];
if(fgets(linha, BUF_SIZE, stdin) == NULL)
return 0;
if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
COORDENADA coord = {*col - 'a', *lin - '1'};
jogar(e, coord);
mostrar_tabuleiro(e);
}
return 1;
}
