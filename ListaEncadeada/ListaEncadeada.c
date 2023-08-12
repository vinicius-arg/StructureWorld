#include "ListaEncadeada.h"

bool compare(ITEM x, ITEM y) {
    return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(ITEM x, ITEM y) {
    return compare(x, y) == 0;
}

void inicializar(LISTA *l) {
    l->head = NULL;
    l->tail = NULL;
    l->tamanho = 0;
}

int tamanho(LISTA *l) {
    return l->tamanho;
}

ITEM head(LISTA *l) {
    if (l->head)
        return l->head->item;
    else 
        exit(EXIT_FAILURE);
}

ITEM tail(LISTA *l) {
    if (l->tail)
        return l->tail->item;
    else 
        exit(EXIT_FAILURE);
}

bool cheia(LISTA *l) {
    printf("\nTamanho: %d; memoria disponivel", l->tamanho);
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
    if (l->head->prox == NULL)
        l->tail = l->head;
    return true;
}

bool inserirNoFinal(ITEM item, LISTA *l) {
    l->tail->prox = criarNode(item, NULL);
    l->tail = l->tail->prox;
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

NODE *NodePosicao(int n, LISTA *l) {
    NODE *p = l->head;

    if (n < 0 || n >= tamanho(l))
        return NULL;
    for (int i = 0; i < n; i++) {
        p = p->prox;
    }

    return p; // Aponta pro n-esimo nodo
}

ITEM enesimo(int n, LISTA *l) {
    NODE *p = NodePosicao(n, l);

    if (p != NULL)
        return p->item;
    else {
        printf("\nPosicao inexistente.");
        exit(EXIT_FAILURE);
    }
}

bool alterar (ITEM item, int pos, LISTA *l) {
    NODE *p = NodePosicao(pos, l);

    if (p != NULL) {
        p->item = item;
        return true;
    } else 
        return false;
}

bool inserirNaPos(ITEM item, int pos, LISTA *l) {
    if (pos == 0) {
        inserir(item, l); // Inserção na cabeça
        return true;
    }

    if (pos == tamanho(l)-1) {
        inserirNoFinal(item, l);
        return true;
    }

    NODE *p = NodePosicao(pos-1, l); // Nodo antecessor

    if (p == NULL || cheia(l))
        return false;

    p->prox = criarNode(item, p->prox);
    l->tamanho++;
    return true;
}

bool remover(ITEM item, LISTA *l) {
    if (vazia(l))
        return false;
    
    NODE *pAntecessor = l->head;

    if (igual(l->head->item, item)) {
        // Remoção de nodo da cabeça da lista
        l->head = l->head->prox;
        free(pAntecessor);
        l->tamanho--;
        return true;
    }

    if(igual(l->tail->item, item)) {
        // Remoção de nodo na cauda
        NODE *pPenultimo = NodePosicao(tamanho(l)-2, l);
        l->tail = pPenultimo;
        free(pPenultimo->prox);
        pPenultimo->prox = NULL;
        l->tamanho--;
        return true;
    }
    
    while (pAntecessor->prox != NULL) {
        NODE *pAtual = pAntecessor->prox;

        if (igual(pAtual->item, item)) {
            // Remoção arbitrária, exceto cabeça
            pAntecessor->prox = pAtual->prox;
            free(pAtual);
            l->tamanho--;
            return true;
        }

        pAntecessor = pAntecessor->prox;
    }
    return false; // Item não encontrado
}

bool removerDaPos(int pos, LISTA *l) {
    NODE *p = NodePosicao(pos, l);

    if (p == NULL)
        return false;

    remover(p->item, l);
    return true;
}

// Função com bug
LISTA *clonar(LISTA *l) {
    LISTA *novaLista;

    inicializar(novaLista);

    novaLista->tamanho = l->tamanho;

    NODE *pLista = l->head;
    NODE *p = criarNode(pLista->item, NULL);

    novaLista->head = p;

    while(pLista->prox != NULL) {
        p->prox = criarNode(pLista->prox->item, NULL);
        
        p = p->prox;
        pLista = pLista->prox;
    }

    novaLista->tail = p;

    return novaLista;
}

void exibirLista(LISTA *l) {
    NODE *p = l->head;
    int pos = 0, index = tamanho(l)-1;

    printf("\n[");

    while (p != NULL) {
        printf(_ITEM_, p->item);
        p = p->prox;

        if (pos != index)
            printf(", "); 
        pos++;
    }

    printf("]");
}

void limpar(LISTA *l) {
    NODE *p = l->head;

    while(remover(p->item, l)) {
        p = p->prox;
    }
    l->head = NULL;
    l->tail = NULL;
    l->tamanho = 0;
}

void destruir(LISTA *l) {
    limpar(l);
}