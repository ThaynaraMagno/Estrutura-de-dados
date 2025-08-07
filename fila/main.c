#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void menu() {
    printf("\n========= MENU FILA =========\n");
    printf("1. Inserir elemento na fila\n");
    printf("2. Remover elemento da fila\n");
    printf("3. Consultar início da fila\n");
    printf("4. Verificar se a fila está vazia\n");
    printf("5. Verificar se a fila está cheia\n");
    printf("0. Sair\n");
    printf("=============================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Fila f;
    int opcao, valor;

    inicializar(&f);

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                if (enfileirar(&f, valor))
                    printf("Valor %d inserido com sucesso!\n", valor);
                else
                    printf("Erro: fila cheia!\n");
                break;

            case 2:
                if (desenfileirar(&f, &valor))
                    printf("Valor %d removido do inicio da fila.\n", valor);
                else
                    printf("Erro: fila vazia!\n");
                break;

            case 3:
                if (frente(&f, &valor))
                    printf("Inicio da fila: %d\n", valor);
                else
                    printf("Fila está vazia.\n");
                break;

            case 4:
                if (esta_vazia(&f))
                    printf("Sim! A fila esta vazia.\n");
                else
                    printf("Nao. A fila tem elementos.\n");
                break;

            case 5:
                if (esta_cheia(&f))
                    printf("Sim! A fila esta cheia.\n");
                else
                    printf("Nao. Ainda ha espaco na fila.\n");
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
