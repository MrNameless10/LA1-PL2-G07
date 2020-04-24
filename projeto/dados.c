#include "dados.h"
#include "logica.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int x,y;
    for(y=0;y<8;y++) {
        for (x=0; x<8; x++) {
            e->tab[x][y] = VAZIO;
        }
    }

    e->ultima_jogada.x = 4;
    e->ultima_jogada.y = 4;
    e->tab[4][4] = BRANCA; //posicao da peca branca no inicio do jogo
    e->num_jogadas = 0;
    e->jogador_atual = 1;
    e->num_comandos = 0;
    //e->jogadas

    return e;
}

int obter_jogador_atual(ESTADO *e) {
    return e->jogador_atual;
}

int obter_numero_de_jogadas(ESTADO *e) {
    return e->num_jogadas;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    return e->tab[c.x][c.y];
}

CASA obter_casa(ESTADO *e,int x,int y){
    return e->tab[x][y];
}

COORDENADA obter_ultima_jogada(ESTADO *e){
    return e->ultima_jogada;
}

void alterar_casa(ESTADO *e, COORDENADA c)
{
    int x = obter_ultima_jogada(e).x;
    int y = obter_ultima_jogada(e).y;

    e -> tab[x][y] = PRETA;
    e -> tab[c.x][c.y] = BRANCA;
}

void alterar_ultima_jogada(ESTADO *e, COORDENADA c) {
    e->ultima_jogada.x = c.x;
    e->ultima_jogada.y = c.y;
}

int add_comando(ESTADO *e){
    return e->num_comandos += 1;
}

void alterar_jogador_atual(ESTADO *e){
    if(obter_jogador_atual (e) == 1) e->jogador_atual = 2;
    else e->jogador_atual = 1;
}

void alterar_jogadas(ESTADO *e, COORDENADA c){

    if(e->jogador_atual == 1){
        e->jogadas[e->num_jogadas].jogador1.x = c.x;
        e->jogadas[e->num_jogadas].jogador1.y = c.y;
    } else {
        e->jogadas[e->num_jogadas].jogador2.x = c.x;
        e->jogadas[e->num_jogadas].jogador2.y = c.y;
    }
}

int fim_de_jogo(ESTADO *e, COORDENADA c) {
    COORDENADA cor;
    if (c.y == 7 && c.x == 7) return 2;
    if (c.y == 0 && c.x == 0) return 1;
    if (bloqueado(e,c)==1) return (obter_jogador_atual(e)== 1 ? 2 : 1);
    for (int i = c.y - 1; i <= c.y + 1; i++) {
        for (int k = c.x - 1; k <= c.x + 1; k++) {
            cor.x = i;
            cor.y = k;
            if (valida_jogada(e, cor)==0) return 0;
        }
    }
    return (obter_jogador_atual(e)== 1 ? 2 : 1);
}

int bloqueado (ESTADO *e, COORDENADA c){
    COORDENADA cor;
    int r=0;
    cor.x = c.x+1;
    cor.y = c.y;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x+1;
    cor.y = c.y+1;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x+1;
    cor.y = c.y-1;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x;
    cor.y = c.y+1;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x;
    cor.y = c.y-1;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x-1;
    cor.y = c.y;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x-1;
    cor.y = c.y+1;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;
    cor.x = c.x-1;
    cor.y = c.y-1;
    if(e->tab[cor.x][cor.y] != VAZIO || valida_jogada(e,cor)==2) r+=1;

    if(r==8) return 1;
    else return 0;
}

int jogadas_guardadas(ESTADO *e, int i, int j) {
    if (i < e->num_jogadas)
        return 1;
    else if (e->num_jogadas == i) {
        if (e->jogador_atual == 1)
            return 0;
        else if (j == 1)
            return 1;
    }
    return 0;
}

char* str_jogada_guardada(ESTADO *e, int i, int j) {
    char *string = calloc(3, sizeof(char));
    if (j == 1) {
        string[0] = e->jogadas[i].jogador1.x + 'a';
        string[1] = e->jogadas[i].jogador1.y + '1';
    } else {
        string[0] = e->jogadas[i].jogador2.x + 'a';
        string[1] = e->jogadas[i].jogador2.y + '1';
    }
    return string;
}

void alterar_num_jogadas(ESTADO *e){
    if (obter_jogador_atual(e)== 1)
        e->num_jogadas++;
}

int obter_num_comandos (ESTADO *e){
    return e->num_comandos;
}

void jogadas_anteriores_guardadas(ESTADO *e, char c, int n) {
    if (e->jogador_atual == 2) {
        e->jogadas[e->num_jogadas].jogador2.x = c - 'a';
        e->jogadas[e->num_jogadas].jogador2.y = n - 1;
        e->jogador_atual = 1;
        e->num_jogadas++;
    }else{
        e->jogadas[e->num_jogadas].jogador1.x = c - 'a';
        e->jogadas[e->num_jogadas].jogador1.x = n - 1;
        e->jogador_atual = 2;
    }
}

void lelinha(char const *linha, int nlinha, ESTADO *e){
    for(int i = 7; i >= 0; i--){
        if(linha[i] == '*'){
            e->tab[i][nlinha] = BRANCA;
            e->ultima_jogada.x = i;
            e->ultima_jogada.y = nlinha;
        }else if(linha[i] == '#'){
            e->tab[i][nlinha] = PRETA;
        }else e -> tab[i][nlinha] = VAZIO;
    }
}

/*ESTADO *novo_estado(FILE *jogo) {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    char linha[25];
    int c;
    int x,y;
    for(y=0;y<8;y++) {
        for (x=0; x<8; x++) {
            if(fscanf(jogo,"%d",&c) == 46) e->tab[x][y] = VAZIO;
            if(fscanf(jogo,"%d",&c) == 42){
                e->tab[x][y] = BRANCA;
                e->ultima_jogada.x = x;
                e->ultima_jogada.y = y;
            }
            if(fscanf(jogo,"%d",&c) == 35) e->tab[x][y] = PRETA;
        }
    }

    //e->tab[ultima_jogada.x][ultima_jogada.y] = BRANCA; //posicao da peca branca no inicio do jogo
    //e->num_jogadas = 0;
    //e->jogador_atual = 1;
    //e->num_comandos = 0;
    //e->jogada
    return e;
}*/

void reset_estado(ESTADO *e){
    int x, y;
    for(y=0;y<8;y++){
        for (x=0; x<8; x++){
            e->tab[x][y] = VAZIO;
        }
    }

    e->ultima_jogada.x = 4;
    e->ultima_jogada.y = 4;
    e->tab[4][4] = BRANCA;
    e->num_jogadas = 0;
    e->jogador_atual = 1;
}

void posicao(int num, ESTADO *e){
    reset_estado(e);
    for (int i = 0; i < num; i++){
        jogar(e, e->jogadas[i].jogador1);
        jogar(e, e->jogadas[i].jogador2);
    }
}

void decrementa_ncomandos(ESTADO *e){
    e->num_comandos = e->num_comandos - 1;
}

LISTA posicoes_possiveis(ESTADO *e, LISTA l){

    COORDENADA c1 = obter_ultima_jogada(e), c2, *ec;

    for (int i = c1.y - 1; i <= c1.y + 1; i++){
        for (int j = c1.x - 1; j <= c1.x + 1; ++j) {
            c2.y = i;
            c2.x = j;
            if (valida_jogada(e, c2)==1){
                ec = malloc(sizeof(COORDENADA));

                ec->y = c2.y;
                ec->x = c2.x;

                l = insere_cabeca(l, ec);
            }
        }
    }

    return l;
}

float distancia_euclidiana(COORDENADA c1 ,COORDENADA c2){

    float d = sqrtf(pow(c1.y - c2.y, 2) + pow(c1.x - c2.x, 2));
    return d;
}

int tamanho_lista(LISTA l){
    int tamanho;
    tamanho = sizeof(l)/ sizeof(l[0]);
    return tamanho;
}

/*ESTADO cabeca_proxlista (LISTA l) {
    COORDENADA *c1;
    LISTA m = l;
    m = proximo(l);
    c1= devolve_cabeca(m);
    return c1;
}
 */