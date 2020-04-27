#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

#define BUF_SIZE 1024

int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while (jogar(e, obter_ultima_jogada(e)) == 0) {
        interpretador(e);
    }
    return 0;

}

/*int main(int argc, char *argv[]){
    char *filename;
    char *filename2;
    ESTADO *e = inicializar_estado();

    if (argc < 2)
    {
        printf("Missing Filename\n");
        return(1);
    }
    else{
        filename = argv[1];
        filename2 = argv[2];
        printf("Filename : %s\n", filename);
        printf("Filename2 : %s\n", filename2);
    }

    ler(filename,e);
    jog(e);
    gr(filename2,e);

    return(0);
}*/
