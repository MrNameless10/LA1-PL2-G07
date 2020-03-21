#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camada de dados.h"
#include "camada de interface.h"

#define BUF_SIZE 1024

// Função que deve ser colocada no ficheiro main.c
int main()
{
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}