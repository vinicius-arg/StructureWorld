#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define print_array(x, y) print_array_impl(x, #x, y)

void print_array_impl(int *v, char* name, int length) {
    printf("%s[] = ", name);
    
    for (int i = 0; i < length; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

void merge(int *v, int *w, int i, int m, int j) {
    int i1 = i; // Início da parte esquerda
    int i2 = m + 1; // Início da parte direita
    int k = i; // Variável auxiliar

    while (i1 <= m && i2 <= j) { // Percorre vetor da esquerda e direita, ordenando w alternadamente
        if (v[i1] < v[i2]) // Compara o elemento do vetor v1[i..m] com o do vetor v2[m+1..j]
            w[k++] = v[i1++]; // Elemento de v1 escolhido
        else 
            w[k++] = v[i2++]; // Elemento de v2 escolhido
    }

    while (i1 <= m) // Copiar elementos restantes de v1
        w[k++] = v[i1++];

    while (i2 <= j) // Copiar elementos restantes de v2
        w[k++] = v[i2++];

    // Copiar valores ordenados de w para v
    for (k = i; k <= j; k++) {
        v[k] = w[k];
    }
}

void mergesort(int *v, int *w, int i, int j) {
    if (i < j) {
        int m = i + (j - i) / 2;

        mergesort(v, w, i, m);
        mergesort(v, w, m + 1, j);
        merge(v, w, i, m, j);
    }
}

void sort(int *v, int length) {
    int *buffer = malloc(sizeof(int)*length);

    // Fazendo buffer ser uma cópia do vetor v
    for (int i = 0; i < length; i++) {
        buffer[i] = v[i];
    }

    mergesort(v, buffer, 0, length-1);

    free(buffer);
}

int main() {
    int v[5] = {3, 1, 19, 7, 12};

    sort(v, 5);
    print_array(v, 5);

    return 0;
}
