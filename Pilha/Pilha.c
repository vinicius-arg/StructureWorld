#include "Pilha.h"

void inicializar(PILHA *p) {
    p->topo = NULL;
    p->tamanho = 0;
}

bool compare(ITEM *x, ITEM *y) {
    return strcmp(x, y);
}

bool igual(ITEM *x, ITEM *y) {
    return compare(x, y) == 0;
}

int tamanho(PILHA *p) {
    return p->tamanho;
}

bool vazia(PILHA *p) {
    return tamanho(p) == 0;
}

bool cheia(PILHA *p) {
    return tamanho(p) == MAX;
}

void exibirItem(ITEM *item) {
    printf("%20s", item);
}

void exibir(PILHA *p) {
    if (vazia(p)) {
        printf("\n** Pilha vazia");
        return;
    }

    NODE *elem = p->topo;

    while (elem) {
        printf("\n[ ");
        exibirItem(elem->item);
        printf(" ]");

        elem = elem->prox;
    }
}

NODE *criarNode(ITEM *item, NODE *prox) {
    NODE *p = (NODE*) malloc(sizeof(NODE));

    if (!p) {
        printf("\n** Nao foi possivel alocar memoria.");
        exit(EXIT_FAILURE);
    }

    strcpy(p->item, item);
    p->prox = prox;

    return p;
}

bool empilhar(ITEM *item, PILHA *p) {
    if (cheia(p))
        return false;

    p->topo = criarNode(item, p->topo);

    p->tamanho++;

    printf("\nNova pilha: ");
    exibir(p);

    return true;
}

ITEM *topo(PILHA *p) {
    if (vazia(p))
        return NULL; // Não encontrou
    return p->topo->item;
}

ITEM *desempilhar(PILHA *p) {
    if (vazia(p)) {
        printf("\n** Impossivel desempilhar");
        return NULL;
    }

    NODE *topo = p->topo;
    ITEM *item = (ITEM*) malloc(MAX_CHR);
    strcpy(item, p->topo->item);

    p->topo = p->topo->prox;
    free(topo);
    
    p->tamanho--;
    return item;
}

void limpar(PILHA *p) {
    if (vazia(p)) {
        printf("\n** Pilha vazia");
    }

    NODE *elem = p->topo;

    while (elem) {
        desempilhar(p);
        elem = elem->prox;    
    }
}

void destruir(PILHA *p) {
    limpar(p);
}