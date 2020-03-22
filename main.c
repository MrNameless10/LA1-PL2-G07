#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "interface.h"
#include "logica.h"

#define BUF_SIZE 1024

int main()
{
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while (jogar(e,obter_ultima_jogada(e))==0) {
        interpretador(e);
    }
    return 0;
}
