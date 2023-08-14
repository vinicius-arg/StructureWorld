#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Pilha.c"

void menu() {
    printf("\n\nO que quer fazer?");
    printf("\n0 - Sair do menu");
    printf("\n1 - Ver tamanho da pilha");
    printf("\n2 - Ver topo da pilha");
    printf("\n3 - Empilhar");
    printf("\n4 - Desempilhar");
    printf("\n5 - Exibir pilha");
    printf("\n6 - Limpar pilha");
    printf("\n7 - Destruir pilha");
    printf("\nEscolha: ");
}

int main() {
    ITEM item[MAX_CHR];
    int escolha;

    PILHA p;
    inicializar(&p);
    
    do {
        menu();
        scanf("%d", &escolha);

        switch (escolha) {
            case 0:
                printf("\nSaindo.");
                break;
            case 1:
                printf("\nTamanho: %d", p.tamanho);
                break;
            case 2:
                printf("\nElemento do topo: ");
                printf(_ITEM_, p.topo->item);
                break;
            case 3:
                printf("\nDigite um item para colocar na pilha: ");
                scanf(_ITEM_, item);
                empilhar(item, &p);
                break;
            case 4:
                printf("\nDesempilhando...");
                printf("\nItem retornado: ");
                printf(_ITEM_, desempilhar(&p));
                break;
            case 5: exibir(&p); break;
            case 6: limpar(&p); break;
            case 7: destruir(&p); break;
        }
    } while (escolha);
}