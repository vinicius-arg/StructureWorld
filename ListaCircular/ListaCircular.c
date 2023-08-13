#include "ListaCircular.h"

void inicializar(LISTA *l) {
    l->head = (NODE*) malloc(sizeof(NODE));
    l->head->prox = l->head;
    l->tamanho = 0;
}

bool compare(ITEM x, ITEM y) {
    x = (int) x;
    y = (int) y;
    return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(ITEM x, ITEM y) {
    return compare(x, y) == 0;
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

int buscar(ITEM item, LISTA *l) {
    NODE *p = l->head;

    for (int i = 0; i < tamanho(l); i++) {
        if (igual(item, p->item))
            return i;
        p = p->prox;
    }

    return -1; // Não achou
}

ITEM enesimo(int n, LISTA *l) {
    if (n < 0 || n >= tamanho(l)) {
        printf("**Indice invalido");
        exit(EXIT_FAILURE);
    }

    NODE *p = l->head;

    for (int i = 0; i < n; i++) {
        p = p->prox;
    }

    return p->item;
}

NODE *criarNode(ITEM item, NODE *prox) {
    NODE *pNovo = (NODE*) malloc(sizeof(NODE));

    if (!pNovo) {
        printf("Nao foi possivel alocar memoria.");
        exit(EXIT_FAILURE);
    }

    pNovo->item = item;
    pNovo->prox = prox;

    return pNovo;
}

bool inserir(ITEM item, LISTA *l) {
    if (cheia(l))
        return false;
    l->head->prox = criarNode(item, l->head->prox);
    l->tamanho++;

    return true;
}

bool remover(int n, LISTA *l) {
    if (n < 0 || n >= tamanho(l))
        return false;

    NODE *p = l->head;
    NODE *pAtual;

    for (int i = 0; i < n-1; i++) {
        p = p->prox; // Antecessor do nó a ser removido
    }

    pAtual = p->prox;
    p->prox = pAtual->prox;
    free(pAtual);
    pAtual = NULL;

    l->tamanho--;
    return true;
}

void exibirLista(LISTA *l) {
    NODE *p = l->head->prox;

    printf("[");
    for (int i = 0; i <= tamanho(l); i++) {
        printf(_ITEM_, p->item);
        p = p->prox;

        if (i != tamanho(l)-1)
            printf(", ");
    }
    printf("]");
}