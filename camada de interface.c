#include <stdio.h>
#include <string.h>
#include "logica do programa.h"
#include "camada de dados.h"

#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    int x ,y;
    for(y=0;y<8; y++){
        if(y==0) printf("8 ");
        if(y==1) printf("7 ");
        if(y==2) printf("6 ");
        if(y==3) printf("5 ");
        if(y==4) printf("4 ");
        if(y==5) printf("3 ");
        if(y==6) printf("2 ");
        if(y==7) printf("1 ");
        for(x=0;x<8;x++){
            if (x==7 && y==0) printf("2");
            else if (x==0 && y==7)printf("1");
            else if (obter_casa(e,x,y)==BRANCA) printf("*");
            else if (obter_casa(e,x,y)==PRETA) printf("#");
            else if (obter_casa(e,x,y)==VAZIO) printf(".");
        }
        printf("\n");
    }
    printf("  abcdefgh");
    printf("\n");
}


int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    
    if(fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
       COORDENADA coord = {*col - 'a', *lin - '1'};
       jogar(e, coord);
       mostrar_tabuleiro(e);
    }
    
    return 1;
}
