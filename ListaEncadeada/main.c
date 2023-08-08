#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaEncadeada.c"

void menu() {
    printf("\nO que quer fazer?");
    printf("\n0 - Sair do menu");
    printf("\n1 - Inicializar lista");
    printf("\n2 - Inserir item");
    printf("\n3 - Buscar um item");
    printf("\n4 - Exibir a lista");
    printf("\nEscolha: ");
}

int main() {
    int escolha;
    LISTA l;
    ITEM item;

    do {
        menu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 0:
                printf("\nSaindo...");
                break;
            case 1: inicializar(&l); break;
            case 2:
                printf("\nDigite um item: ");
                scanf(_ITEM_, &item);  
                inserir(item, &l);
                break;
            case 3:
                printf("\nDigite um item: ");
                scanf(_ITEM_, &item);
                printf("\nPosicao: %d", buscar(item, &l));
                break;
            case 4: exibirLista(&l); break;
            default: printf("\n** Operacao invalida.");
        }
    } while (escolha != 0);

    return 0;
}