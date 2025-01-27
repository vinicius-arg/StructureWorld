#include <stdio.h>
#include <stdlib.h>

void construir_heap(int* v, int n);
void heapify(int* v, int t, int i);
void heapsort(int* v, int n);
void trocar(int* a, int* b);
int esquerdo(int i);
int direito(int i);
void imprimir_v(int* v, int n);

int main() {
    int v[] = {17, 20, 3, 29, 15, 2, 5};
    
    heapsort(v, 7);

    imprimir_v(v, 7);

    return 0;
}

void construir_heap(int* v, int n) {
    int ultimo_pai = ((n - 1) - 1) / 2; // Último nó com filhos

    for (int i = ultimo_pai; i >= 0; i--) {
        heapify(v, n, i);
    }
}

void heapify(int* v, int t, int i) {
    int pai = i, esq = esquerdo(i), dir = direito(i);

    /* Filho da esquerda é maior */
    if (esq < t && v[esq] > v[pai]) pai = esq;

    /* Filho da direita é maior */
    if (dir < t && v[dir] > v[pai]) pai = dir;

    /* Troca */
    if (pai != i) {
        trocar(&v[pai], &v[i]);
        heapify(v, t, pai); // Pai é esq ou dir
    }
}

void heapsort(int* v, int n) {
    construir_heap(v, n);

    for (int i = n - 1; i > 0; i--) {
        trocar(&v[0], &v[i]); // Trocando nó da raiz pelo último nó
        heapify(v, i, 0); // Aplicando heapify na raiz
    }
}

void trocar(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int esquerdo(int i) {
    return 2*i + 1;
}

int direito(int i) {
    return 2*i + 2;
}

void imprimir_v(int* v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}
