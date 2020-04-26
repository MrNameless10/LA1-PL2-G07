#include "dados.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define BUF_SIZE 1024
int interpretador (ESTADO *e);

void mostrar_prompt(ESTADO *e){
    printf("# %d  PL%d  (%d)>", add_comando(e), obter_jogador_atual(e),obter_numero_de_jogadas(e)+1);
}

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
            printf(" ");
        }
        printf("\n");
        i--;
    }
    printf("  a b c d e f g h");
    printf("\n");
    mostrar_prompt(e);
}

void movs(FILE *jogo, ESTADO *e);

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
        if((fgets(linha, 50, jogo) != NULL)) lelinha(linha, i, e);
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
    mostrar_tabuleiro(e);
}

void gr(char *ficheiro, ESTADO *e){
    FILE *jogo;
    jogo = fopen(ficheiro, "w");

    escreve_tabuleiro(e, jogo);
    fprintf(jogo, "\n");
    movs(jogo, e);
    fclose(jogo);
}

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

    if((fim_de_jogo (e,c))){      //para que o jogo acabe com o comando jog.
        mostrar_tabuleiro(e);
        printf ("\nGAME OVER. Parabéns jogador %d!\n",fim_de_jogo (e,c));
        exit(0);
    }

}

void jog2(ESTADO *e) { //contém a Estratégia baseada na paridade!!!
    COORDENADA c, *a;
    LISTA l = criar_lista();
    c.x = 0;
    c.y = 0;
    l = posicoes_possiveis(e, l);

    while (lista_esta_vazia(l)==0) {
        a = devolve_cabeca(l);
        c = *a;
        if(bloqueado(e,c) % 2 == 0){
            break;
        }
        l = proximo(l);
    }
    if (lista_esta_vazia(l)!=0) jog(e);

    jogar(e,c);

    if((fim_de_jogo (e,c))){      //para que o jogo acabe com o comando jog.
        mostrar_tabuleiro(e);
        printf ("\nGAME OVER. Parabéns jogador %d!\n",fim_de_jogo (e,c));
        exit(0);
    }

}

int interpretador (ESTADO *e){
    char linha[BUF_SIZE];
    char file[BUF_SIZE];
    char col[2], lin[2];
    int num;
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
        COORDENADA coord = {*col -'a', *lin - '1'};
        if (!(jogar (e, coord))){
            printf ("Jogada impossivel. (TENTE NOVAMENTE)\n");
            decrementa_ncomandos(e);
        }
        else if ((fim_de_jogo (e,coord))) {
            mostrar_tabuleiro(e);
            printf ("\nGAME OVER. Parabéns jogador %d!\n",fim_de_jogo (e,coord));
            exit(0);
        }
        mostrar_tabuleiro(e);

    }else if(strcmp(linha, "Q\n") == 0) exit(0);

    else if(sscanf(linha,"gr %s", file) == 1){

        gr(file,e);
        printf("JOGO GRAVADO\n");
        mostrar_tabuleiro(e);
    }
    else if(sscanf(linha,"ler %s", file) == 1){
        ler(file,e);

    }else if(sscanf(linha,"%s", file) == 1 && !strcmp(file, "movs")){
        movs(stdout, e);
        mostrar_tabuleiro(e);

    }else if(sscanf(linha,"pos %d", &num) == 1){
        posicao(num,e);
        mostrar_tabuleiro(e);

    }else if(sscanf(linha, "%s", file) == 1 && !strcmp(file, "jog")) {
        jog(e);
        mostrar_tabuleiro(e);

    }else if(sscanf(linha, "%s", file) == 1 && !strcmp(file, "jog2")) {
        jog2(e);
        mostrar_tabuleiro(e);

    }else{
        printf ("Jogada impossivel. (TENTE NOVAMENTE)\n");
        decrementa_ncomandos(e);
        mostrar_tabuleiro(e);
    }
    return 0;
}