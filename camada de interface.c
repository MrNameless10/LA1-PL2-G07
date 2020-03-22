#include "camada de dados.h"
#include "logica de programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *e) {
    int x ,y,i=8;
    printf("\n");
    for(y=7;y>=0; y--){
        printf("%d ", i);
        for(x=0;x<8;x++){
            if (x==7 && y==7) printf("2");
            else if (x==0 && y==0)printf("1");
            else if (obter_casa(e,x,y)==BRANCA) printf("*");
            else if (obter_casa(e,x,y)==PRETA) printf("#");
            else if (obter_casa(e,x,y)==VAZIO) printf(".");
        }
        printf("\n");
        i--;
    }
    printf("  abcdefgh");
    printf("\n");
    mostrar_prompt(e);
}

void ler (char *ficheiro, ESTADO *e){
    FILE *jogo;
    jogo = fopen(ficheiro, "r");
    char linha[25];
    e->num_jogadas = -1;
    for (int i = 0; i < 8; i++)
    {
        fgets(linha, 25, jogo);
        get_y(linha, i, e);
    }
    fclose(jogo);
}

void gr (char *ficheiro, ESTADO *e) {
    FILE *jogo;
    jogo = fopen(ficheiro, "w");
    mostrar_tabuleiro(e);
    fclose(jogo);
}


int interpretador (ESTADO *e){
	char linha[BUF_SIZE];
	char col[2], lin[2];
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
    	COORDENADA coord = {*col -'a', *lin - '1'};
    	if (!(jogar (e, coord))) printf ("Jogada impossivel. (TENTE NOVAMENTE)\n");
    	else if (fim_de_jogo (e,coord)) {
    			printf ("GAME OVER. Parabéns jogador %d!\n",fim_de_jogo (e,coord)); 
    			exit(0);
        }
    	mostrar_tabuleiro(e);
    }
    return 0;
}