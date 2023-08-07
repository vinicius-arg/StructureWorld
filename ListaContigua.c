#include "ListaContigua.h"

void inicializar(LISTA_CONT *l) {
    l->tamanho = 0;
    l->inicio = 0;
    l->fim = 0;
}

// Por que o professor declarou como "char"?
int compare(ITEM x, ITEM y) {
    return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(ITEM x, ITEM y) {
    return compare(x,y) == 0;
}

int tamanho(LISTA_CONT *l) {
    return l->tamanho;
}

bool cheia(LISTA_CONT *l) {
    return tamanho(l) == MAX;
}

bool vazia(LISTA_CONT *l) {
    return tamanho(l) == 0;
}

bool inserir(ITEM item, LISTA_CONT *l) {
    if (cheia(l) == true)
        return false;
    else
        l->itens[l->tamanho++] = item;
    return true;
}

int buscar(ITEM item, LISTA_CONT *l) {
    for (int pos = 0; pos < l->tamanho; pos++) {
        if (igual(l->itens[pos], item))
            return pos;
    }

    return -1;
}

ITEM enesimo(int n, LISTA_CONT *l) {
    if (n < 0 || n > tamanho(l))
        return -1;
    else {
        return l->itens[n];
    }
}

bool alterar(ITEM item, int pos, LISTA_CONT *l) {
    if (pos < 0 || pos >= tamanho(l))
        return false;
    else
        l->itens[pos] = item;
    return true;
}

bool inserirNaPos(ITEM item, int pos, LISTA_CONT *l) {
    if ((pos < 0 || pos > tamanho(l)) || cheia(l) == true)
        return false;
    else {
        if (pos < tamanho(l)) {
            // Inserção no meio
            for (int i = tamanho(l); i > pos; i--) {
                l->itens[i] = l->itens[i-1];
            }

            l->itens[pos] = item;
            l->tamanho++;
        } else
            l->itens[pos-1] = item;
        return true;
    }
}

bool remover(ITEM item, LISTA_CONT *l) {
    for (int i = 0; i < tamanho(l); i++) {
        if (igual(l->itens[i], item)) {
            for (int j = i; j < tamanho(l); j++) {
                l->itens[j] = l->itens[j+1]; 
            }
            l->tamanho--;
            return true;
        }
    }
    return false;
}

void exibirItem(ITEM item) {
    printf(_ITEM_, item);
}

void exibirLista(LISTA_CONT *l) {
    printf("\nLista: [");

    for (int i = 0; i < tamanho(l); i++) {
        exibirItem(l->itens[i]);
        if (i < tamanho(l)-1)
            printf(", ");
    }

    printf("]");
}

void limpar(LISTA_CONT *l) {
    l->tamanho = 0;
}

void destruir(LISTA_CONT *l) {
    limpar(l);
}
