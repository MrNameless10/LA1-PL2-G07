void mostrar_tabuleiro(ESTADO *e) {
}

// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {
char linha[BUF_SIZE];
char col[2], lin[2];
5
if(fgets(linha, BUF_SIZE, stdin) == NULL)
return 0;
if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
COORDENADA coord = {*col - 'a', *lin - '1'};
jogar(e, coord);
mostrar_tabuleiro(e);
}
return 1;
}
