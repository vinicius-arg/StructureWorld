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
    printf("\n5 - Buscar n-esimo elemento");
    printf("\n6 - Inserir na posicao");
    printf("\n7 - Alterar um item");
    printf("\n8 - Remover um item");
    printf("\n9 - Limpar a lista");
    printf("\n10 - Inserir no final");
    printf("\n11 - Exibir cabeca e cauda da lista");
    printf("\n12 - Remover por posicao");
    printf("\n13 - Clonar lista");
    printf("\nEscolha: ");
}

int main() {
    int escolha, pos;
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
            case 5:
                printf("\nN-esimo elemento: ");
                scanf("%d", &pos);
                printf("\nValor: %d", enesimo(pos, &l));
                break;
            case 6:
                printf("\nDigite um item e uma posicao: ");
                scanf(_ITEM_, &item);
                scanf("%d", &pos);
                inserirNaPos(item, pos, &l);
                break;
            case 7:
                printf("\nDigite um item e uma posicao: ");
                scanf(_ITEM_, &item);
                scanf("%d", &pos);
                alterar(item, pos, &l);
                break;
            case 8:
                printf("\nDigite um item: ");
                scanf(_ITEM_, &item);
                remover(item, &l);
                break;
            case 9: limpar(&l); break;
            case 10:
                printf("\nDigite um item: ");
                scanf(_ITEM_, &item);
                inserirNoFinal(item, &l);
                break;
            case 11:
                printf("\nCabeca: ");
                printf(_ITEM_, head(&l));;
                printf("\nCauda: ");
                printf(_ITEM_, tail(&l));
                break;
            case 12:
                printf("\nDigite uma posicao: ");
                scanf("%d", &pos);
                removerDaPos(pos, &l);
                break;
            case 13:
                printf("\nTeste de clonar lista: ");
                LISTA *g = clonar(&l);
                exibirLista(g);
                break;
            default: printf("\n** Operacao invalida.");
        }
    } while (escolha != 0);

    return 0;
}