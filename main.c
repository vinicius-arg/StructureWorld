#include <stdio.h>
#include <stdlib.h>
#include "ListaContigua.h"
#include "ListaContigua.c"

void menu() {
    printf("\nO que quer fazer?");
    printf("\n0 - Sair do menu");
    printf("\n1 - Inicializar lista");
    printf("\n2 - Inserir item");
    printf("\n3 - Alterar um item");
    printf("\n4 - Inserir em posicao especifica");
    printf("\n5 - Remover item");
    printf("\n6 - Exibir lista");
    printf("\n7 - Limpar lista");
    printf("\nEscolha: ");
}

int main() {
    int escolha, pos;
    LISTA_CONT l;
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
                printf("\nDigite um item e uma posicao: ");
                scanf(_ITEM_, &item);
                scanf("%d", &pos);
                alterar(item, pos, &l);
                break;
            case 4:
                printf("\nDigite um item e uma posicao: ");
                scanf(_ITEM_, &item);
                scanf("%d", &pos);
                inserirNaPos(item, pos, &l);
                break;
            case 5:
                printf("\nDigite um item: ");
                scanf(_ITEM_, &item);
                remover(item, &l);
                break;
            case 6: exibirLista(&l); break;
            case 7: limpar(&l); break;
            default: printf("\n** Operacao invalida."); break;
        }
    } while (escolha != 0);

    return 0;
}