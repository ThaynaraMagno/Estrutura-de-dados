#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void menu() {
    printf("\n===== MENU DA LISTA ENCADEADA =====\n");
    printf("1 - Inserir valor\n");
    printf("2 - Remover valor\n");
    printf("3 - Consultar valor em uma posicao\n");
    printf("4 - Alterar valor em uma posicao\n");
    printf("5 - Ver tamanho da lista\n");
    printf("6 - Verificar se a lista esta vazia\n");
    printf("7 - Imprimir a lista\n");
    printf("0 - Sair do programa\n");
    printf("Opcao: ");
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar(); // consome enter pendente
    getchar(); // espera enter real
    system("clear"); // se estiver no Windows, use "cls"
}

int main() {
    Lista lista;
    criarLista(&lista);

    int opcao, posicao, valor;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o valor a inserir: ");
                scanf("%d", &valor);
                printf("Informe a posicao (1 ate %d): ", lista.tamanho + 1);
                scanf("%d", &posicao);
                if (inserirNaPosicao(&lista, posicao, valor))
                    printf("Valor inserido com sucesso.\n");
                else
                    printf("Nao foi possivel inserir. Posicao invalida.\n");
                pausar();
                break;

            case 2:
                printf("Informe a posicao para remocao (1 ate %d): ", lista.tamanho);
                scanf("%d", &posicao);
                if (removerNaPosicao(&lista, posicao, &valor))
                    printf("Valor removido: %d\n", valor);
                else
                    printf("Nao foi possivel remover. Verifique a posicao.\n");
                pausar();
                break;

            case 3:
                printf("Informe a posicao que deseja consultar: ");
                scanf("%d", &posicao);
                if (acessarValor(&lista, posicao, &valor))
                    printf("Valor na posicao %d: %d\n", posicao, valor);
                else
                    printf("Posicao invalida.\n");
                pausar();
                break;

            case 4:
                printf("Informe a posicao que deseja alterar: ");
                scanf("%d", &posicao);
                printf("Novo valor: ");
                scanf("%d", &valor);
                if (alterarValor(&lista, posicao, valor))
                    printf("Valor atualizado com sucesso.\n");
                else
                    printf("Nao foi possivel atualizar. Verifique a posicao.\n");
                pausar();
                break;

            case 5:
                printf("A lista possui %d elemento(s).\n", tamanhoLista(&lista));
                pausar();
                break;

            case 6:
                if (estaVazia(&lista))
                    printf("A lista esta vazia.\n");
                else
                    printf("A lista nao esta vazia.\n");
                pausar();
                break;

            case 7:
                imprimirLista(&lista);
                pausar();
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
                pausar();
        }

    } while (opcao != 0);

    liberarLista(&lista);
    return 0;
}
