#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef PILHA_ENCADEADA
#define PILHA_ENCADEADA

#define _ITEM_ "%s"
#define MAX 10
#define MAX_CHR 20

typedef char ITEM;

typedef struct Node {
    ITEM item[MAX_CHR];
    struct Node *prox;
} NODE;

typedef struct {
    NODE *topo;
    int tamanho;
} PILHA;


// Inicializa a pilha
void inicializar(PILHA *p);

// Compara dois itens da pilha
bool compare(ITEM *x, ITEM *y);

// Verifica se dois itens da pilha são iguais
bool igual(ITEM *x, ITEM *y);

// Retorna o tamanho da pilha
int tamanho(PILHA *p);

// Verifica se a lista está vazia, retorna true caso sum
bool vazia(PILHA *p);

// Verifica se a lista está cheia, returna true caso sim
bool cheia(PILHA *p);

// Coloca um item no topo da pilha e retorna true caso a operação ocorra sem impedimentos
bool empilhar(ITEM *item, PILHA *p);

// Retorna o item do topo sem afetar o estado da pilha
ITEM *topo(PILHA *p);

// Tira um elemento do topo da pilha e o retorna caso a operação seja um sucesso
ITEM *desempilhar(PILHA *p);

// Exibe a pilha
void exibir(PILHA *p);

// Limpa a pilha
void limpar(PILHA *p);

// Destrói a pilha
void destruir(PILHA *p);

#endif // PILHA_ENCADEADA