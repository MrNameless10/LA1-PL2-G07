#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada de dados.h"
#include "camada de interface.h"
#include "logica de programa.h"

#define BUF_SIZE 1024

// Função que deve ser colocada no ficheiro main.c
int main()
{
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while (jogar(e,obter_ultima_jogada(e))==0) {
        interpretador(e);
    }
    return 0;
}