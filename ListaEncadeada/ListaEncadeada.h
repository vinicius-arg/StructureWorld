#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA

#define _ITEM_ "%d"

typedef int ITEM;

typedef struct Node {
    ITEM item;
    struct Node *prox;
} NODE;

typedef struct {
    NODE *head;
    NODE *tail;
    int tamanho;
} LISTA;

// Compara dois valores da lista
bool compare(ITEM x, ITEM y);

// Retorna true se x = y e false caso contrario
bool igual(ITEM x, ITEM y);

// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l);

// Retorna o tamanho da lista sequencial
int tamanho(LISTA *l);

// Retorna a cabeça da lista
ITEM head(LISTA *l);

// Retorna a cauda da lista
ITEM tail(LISTA *l);

// Retorna true se a lista estiver cheia
bool cheia(LISTA *l);

// Retorna true se a lista estiver vazia
bool vazia(LISTA *l);

/* 
  Objetivo: Insere o item passado como parametro na lista passada.
            Se o tamanho da lista ja for igual ao tamanho maximo,
            a funcao Inserir retorna false.
*/
bool inserir(ITEM item, LISTA *l);

/*
  Objetivo: Busca na lista o item passado.
            Caso encontre, retorna a posicao (entre 0 e tamanho - 1).
            Caso nao encontre, retorna o valor -1.
*/
int buscar(ITEM item, LISTA *l);

// Retornar o n-esimo elemento da lista sequencial
// Pre-condicao: 0 <= n < tamanho
ITEM enesimo(int n, LISTA *l);

/*
  Objetivo: Altera o item contido em uma dada posicao da lista.
            Caso a posicao exista, retorna true. Caso nao exista,
            a alteracao nao sera feita e retorna false.
*/
bool alterar(ITEM item, int pos, LISTA *l);

/*
  Objetivo: Inserir o item passado como parametro na posicao i da lista.
            Caso a lista nao esteja cheia e a posicao seja valida
            (0<=i<=tamanho), o item sera inserido e a funcao retorna true. 
            Caso contrario, a funcao retorna false para indicar que o item
            nao foi inserido.
 */
bool inserirNaPos(ITEM item, int pos, LISTA *l);

/*
  Objetivo: Remove o item passado da lista. Caso nao seja
            encontrato, retorna false. Se for removido, true.
*/
bool remover(ITEM item, LISTA *l);

// Exibicao da lista sequencial
void exibirLista(LISTA *l);

// Remove todos os valores da lista, deixando-a vazia
void limpar(LISTA *l);

// Destruicao da lista sequencial
void destruir(LISTA *l);

#endif