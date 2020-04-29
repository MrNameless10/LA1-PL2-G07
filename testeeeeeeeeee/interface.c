#include "dados.h"
#include <stdio.h>
#include <stdlib.h>

void movs(FILE *jogo, ESTADO *e){
    char *string;
    for(int i = 0; i <= obter_numero_de_jogadas(e); i++){
        if(jogadas_guardadas(e, i, 1)){
            fprintf(jogo, "%02d: %s", i+1, (string = str_jogada_guardada(e, i, 1)));
            free(string);
        }else break;

        if(jogadas_guardadas(e, i, 2)){
            fprintf(jogo, " %s\n", (string = str_jogada_guardada(e, i, 2)));
            free(string);
        }else break;
    }
}

void escreve_tabuleiro(ESTADO *e, FILE *jogo) {
    int x ,y;
    printf("\n");
    for(y=7;y>=0; y--){
        for(x=0;x<8;x++){
            if (x==7 && y==7) fprintf(jogo, "2");
            else if (x==0 && y==0) fprintf(jogo, "1");
            else if (obter_casa(e,x,y)==BRANCA) fprintf(jogo,"*");
            else if (obter_casa(e,x,y)==PRETA) fprintf(jogo,"#");
            else if (obter_casa(e,x,y)==VAZIO) fprintf(jogo,".");
        }
        fprintf(jogo, "\n");
    }
}

void ler(char *ficheiro, ESTADO *e){
    FILE *jogo;
    jogo = fopen(ficheiro, "r");
    char linha[50],string[50],c1, c2;
    int n1, n2;
    free(e);
    e = inicializar_estado();

    for (int i = 7; i >= 0; i--){    //muda para o novo estado do tabuleiro linha por linha.
        if((fgets(linha, 50, jogo) != NULL)) seeline(linha, i, e);
    }

    while(fgets(linha, 50, jogo) != NULL){
        if(sscanf(linha, "%s %c%d %c%d", string, &c1, &n1, &c2, &n2) == 5){ //com duas jogadas -- 01: e1 e2 (por exemplo)
            jogadas_anteriores_guardadas(e, c1, n1);
            jogadas_anteriores_guardadas(e, c2, n2);
        }else if(sscanf(linha, "%s %c%d", string, &c1, &n1) == 3){ //com uma jogada -- 04: f2 (por exemplo)
            jogadas_anteriores_guardadas(e, c1, n1);
        }
    }
    fclose(jogo);
}

void gr(char *ficheiro, ESTADO *e){
    FILE *jogo;
    jogo = fopen(ficheiro, "w");

    escreve_tabuleiro(e, jogo);
    fprintf(jogo, "\n");
    movs(jogo, e);
    fclose(jogo);
}