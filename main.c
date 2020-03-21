#include "camada_de_dados.h"
#include "camada_de_interface.h"
#include "logica_do_programa.h"

int main() {
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0; 
}
