//
// Created by miguel on 28/04/2020.
//

#ifndef BOT_LISTAS_H
#define BOT_LISTAS_H

/**
\brief Definição genérica das listas ligadas
*/
typedef struct nodo{
    void *valor;
    struct nodo *prox;
}*LISTA, NODO;

/**
\brief Cria um lista ligada @returns apontando para a mesma
*/
LISTA criar_lista();

/**
\brief Insere um valor à cabeça @param l Lista ligada @param valor para ser adicionado @returns apontando para a lista ligada
 */
LISTA insere_cabeca(LISTA l, void *valor);

/**
\brief Devolve a cabeça da lista @param l Lista ligada @returns Valor guardado na cabeça
*/
void *devolve_cabeca(LISTA l);

/**
\brief Devolve o próximo valor da lista @param l Lista ligada @returns Lista que começa no elemento a seguir da lista dada
 */
LISTA proximo(LISTA l);

/**
\brief Remove a cabeça da lista @param l Lista ligada @returns Cauda da lista ligada
 */
LISTA remove_cabeca(LISTA l);

/**
\brief Verifica se a lista está vazia @param l Lista ligada dando @returns 1 se está vazia e 0 senão está
 */
int lista_esta_vazia(LISTA l);

#endif //BOT_LISTAS_H
