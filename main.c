#include "camada de dados.h"
#include "camada de interface.h"
#include "logica do programa.h"

int main() {
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0; 
}
