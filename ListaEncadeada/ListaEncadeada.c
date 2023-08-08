#include "ListaEncadeada.h"

bool compare(ITEM x, ITEM y) {
    return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(ITEM x, ITEM y) {
    return compare(x, y) == 0;
}

void inicializar(LISTA *l) {
    l->head = NULL;
    l->tamanho = 0;
}

int tamanho(LISTA *l) {
    return l->tamanho;
}

bool cheia(LISTA *l) {
    return false;
}

bool vazia(LISTA *l) {
    return tamanho(l) == 0;
}

NODE *criarNode(ITEM item, NODE *prox) {
    NODE *pNovo = (NODE*) malloc(sizeof(NODE));

    if (pNovo == NULL) {
        printf("\nNao foi possivel alocar memoria para um novo nodo.");
        exit(EXIT_FAILURE);
    }

    pNovo->item = item;
    pNovo->prox =  prox;

    return pNovo;
}

bool inserir(ITEM item, LISTA *l) {
    l->head = criarNode(item, l->head);
    l->tamanho++;
    return true;
}

int buscar(ITEM item, LISTA *l) {
    NODE *p = l->head;
    int pos = 0;

    while (p != NULL) {
        if (igual(p->item, item))
            return pos;

        p = p->prox;
        pos++;
    }

    return -1;
}

void exibirLista(LISTA *l) {
    NODE *p = l->head;
    int pos = 0, index = tamanho(l)-1;

    printf("[");

    while (p != NULL) {
        printf(_ITEM_, p->item);
        p = p->prox;

        if (pos != index)
            printf(", "); 
        pos++;
    }

    printf("]");
}