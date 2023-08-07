// Implementação de Lista Sequencial Estática por contiguidade física (vetor)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef LISTA_CONTIGUA
#define LISTA_CONTIGUA

#define MAX 10
#define _ITEM_ "%d" 
// Tem mum jeito melhor de definir uma máscara?

typedef int ITEM;

typedef struct {
    ITEM itens[MAX];
    int tamanho;
    int inicio, fim;
} LISTA_CONT;

// Incializa a lista
void inicializar(LISTA_CONT *l);

// Compara dois itens da lista
int compare(ITEM x, ITEM y);

// Retorna true se x = y e false se não for
bool igual(ITEM x, ITEM y);

// Retorna o tamanho da lista
int tamanho(LISTA_CONT *l);

// Retorna true se a lista estiver cheia, false se não estiver
bool cheia(LISTA_CONT *l);

// Retorna true se a lista estiver vazia, false se não estiver
bool vazia(LISTA_CONT *l);

// Insere um item na lista, se estiver cheia, retorna false
bool inserir(ITEM item, LISTA_CONT *l);

// Busca determinado item na lista e retorna a posição, se não encontrar, retorna -1 
int buscar(ITEM item, LISTA_CONT *l);

// Retorna o enesimo elemento da lista
ITEM enesimo(int n, LISTA_CONT *l);

// Altera um item em determinada posiçao, retorna true se a posição existir
bool alterar(ITEM item, int pos, LISTA_CONT *l);

/* Insere um item em determinada posição caso a mesma seja válida 
e a lista não estiver cheia, retorna true caso a operação seja um sucesso. */
bool inserirNaPos(ITEM item, int pos, LISTA_CONT *l);

// Remove um item e retorna true caso o item exista
bool remover(ITEM item, LISTA_CONT *l);

// Exibe um item da lista
void exibirItem(ITEM item);

// Exibe toda a lista
void exibirLista(LISTA_CONT *l);

// Limpa a lista, deixando-a vazia
void limpar(LISTA_CONT *l);

// Destrói a lista
void destruir(LISTA_CONT *l);

#endif // LISTA_CONTIGUA