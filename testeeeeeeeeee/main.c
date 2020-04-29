#include <stdio.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

int main(int argc, char *argv[]) {
    char *filename;
    char *filename2;
    ESTADO *e = inicializar_estado();

    if (argc < 2) {
        printf("Missing Filename\n");
        return (1);
    } else {
        filename = argv[1];
        filename2 = argv[2];
    }

    ler(filename, e);
    jog(e);
    gr(filename2, e);

    return (0);
}