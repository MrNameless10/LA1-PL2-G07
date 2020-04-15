
#ifndef LA1_PL2_G07_LISTAS_H
#define LA1_PL2_G07_LISTAS_H

typedef struct nodo{
    void *valor;
    struct nodo *prox;
}*LISTA, NODO;

LISTA criar_lista();
LISTA insere_cabeca(LISTA l, void *valor);
void *devolve_cabeca(LISTA l);
LISTA proximo(LISTA l);
LISTA remove_cabeca(LISTA l);
int lista_esta_vazia(LISTA l);

#endif //LA1_PL2_G07_LISTAS_H
