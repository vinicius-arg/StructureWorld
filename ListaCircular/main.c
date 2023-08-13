#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaCircular.h"
#include "ListaCircular.c"

void menu() {
    printf("\nO que quer fazer?");
    printf("\n0 - Sair do menu");
    printf("\n1 - Inicializar lista");
    printf("\n2 - Inserir item");
    printf("\n3 - Buscar um item");
    printf("\n4 - Exibir a lista");
    printf("\n5 - Enesimo item");
    printf("\n6 - Remover item");
    printf("\n7 - Inserir no final");
    printf("\n8 - Limpar lista");
    printf("\nEscolha: ");
}

int main() {
    LISTA l;
    ITEM item;
    int escolha, pos;

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
            case 5:
                printf("\nEnesimo elemento: ");
                scanf("%d", &pos);
                printf("\nValor: %d", enesimo(pos, &l));
                break;
            case 6:
                printf("\nDigite uma posicao: ");
                scanf("%d", &pos);
                remover(pos, &l);
                break;
            default:
                printf("**Opcao invalida");
        }
    } while (escolha != 0);

    return 0;
}