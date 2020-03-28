#include "dados.h"
#include "logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define BUF_SIZE 1024

void mostrar_prompt(ESTADO *e){
    printf("# %d  PL%d  (%d)> ", add_comando(e), obter_jogador_atual(e),obter_numero_de_jogadas(e));
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
        }
        printf("\n");
        i--;
    }
    printf("  abcdefgh");
    printf("\n");
    mostrar_prompt(e);
}

/*void q() {
    FILE *jogo;

    jogo = fopen("file.txt", "w");

    fprintf(jogo, "%s", "Programa terminado");
    fclose(jogo);
}*/

void ler(char *ficheiro, ESTADO *e){//Mostra o tabuleiro guardado mas não continua o jogo nesse tabuleiro (por resolver)
	FILE *jogo;
	char a;
    strcat(ficheiro,".txt");

    if((jogo = fopen(ficheiro,"r")) == NULL){
        printf("Problemas na abertura do arquivo");
        return;
    }
	
    while((a = fgetc(jogo)) != EOF) printf("%c",a);     

    fclose(jogo);
}

void movs(FILE *jogo, ESTADO *e);

void gr(char *ficheiro, ESTADO *e){
	FILE *jogo; int i=8; int result;
	strcat(ficheiro,".txt");
	jogo = fopen(ficheiro, "w"); 
	if (jogo == NULL){ 
		printf("Problemas na criacao do arquivo\n");
		return;
	}
	int x,y;
	fprintf(jogo,"\n");
    for(y=7;y>=0; y--){     //mostrar tabuleiro com fprintf
        fprintf(jogo,"%d ", i);
        for(x=0;x<8;x++){
            if (x==7 && y==7) fprintf(jogo,"2");
            else if (x==0 && y==0) fprintf(jogo,"1");
            else if (obter_casa(e,x,y)==BRANCA) fprintf(jogo,"*");
            else if (obter_casa(e,x,y)==PRETA) fprintf(jogo,"#");
            else if (obter_casa(e,x,y)==VAZIO) fprintf(jogo,".");
        }
        fprintf(jogo,"\n");
        i--;
    }
    fprintf(jogo,"  abcdefgh");
    fprintf(jogo,"\n");		

	fprintf(jogo,"# %d  PL%d  (%d)> ", obter_num_comandos(e), obter_jogador_atual(e),obter_numero_de_jogadas(e)); //prompt com fprintf		  
	if (result == EOF) printf("Erro na Gravacao\n");

    movs(jogo,e);
	fclose(jogo);
}

void movs(FILE *jogo, ESTADO *e){
    char *str;
    for (int i = 0; i <= obter_numero_de_jogadas(e); i++) {
        if (jogadas_guardadas(e, i, 1)) {
            fprintf(jogo, "%02d: %s", i+1, (str = str_jogada_guardada(e, i, 1)));
            free(str);
        } else break;

        if (jogadas_guardadas(e, i, 2)) {
            fprintf(jogo, " %s\n", (str = str_jogada_guardada(e, i, 2)));
            free(str);
        } else break;
    }
}

int interpretador (ESTADO *e){
	char linha[BUF_SIZE];
	char file[BUF_SIZE];
	char col[2], lin[2];
    if (fgets(linha, BUF_SIZE, stdin) == NULL) return 0;
    if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
    	COORDENADA coord = {*col -'a', *lin - '1'};
    	if (!(jogar (e, coord))) printf ("Jogada impossivel. (TENTE NOVAMENTE)\n");
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
    }
    else{
        printf ("Jogada impossivel. (TENTE NOVAMENTE)\n");
        mostrar_tabuleiro(e);
    }

    return 0;
}