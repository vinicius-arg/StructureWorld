#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef LISTA_CIRCULAR
#define LISTA_CIRCULAR

#define _ITEM_ "%d"

typedef int ITEM; 

typedef struct Node {
    ITEM item;
    struct Node *prox;
} NODE;

typedef struct {
    NODE *head;
    int tamanho;
} LISTA;

void inicializar(LISTA *l);
bool compare(ITEM x, ITEM y);
bool igual(ITEM x, ITEM y);
int tamanho(LISTA *l);
bool cheia(LISTA *l);
bool vazia(LISTA *l);
int buscar(ITEM item, LISTA *l);
ITEM enesimo(int n, LISTA *l);
bool inserir(ITEM item, LISTA *l);
bool remover(int n, LISTA *l);
bool inserirNoFinal(ITEM item, LISTA *l);
void exibirLista(LISTA *l);
void limpar(LISTA *l);
void destruir(LISTA *l);

#endif