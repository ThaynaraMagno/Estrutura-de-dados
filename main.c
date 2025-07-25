#include <stdio.h>
#include "lista.h"

void exibir_lista(Lista *l) {
    if (lista_vazia(l)) {
        printf("Lista está vazia.\n");
        return;
    }
    printf("Lista atual:\n");
    for (int i = 1; i <= obter_tamanho(l); i++) {
        int val;
        obter_elemento(l, i, &val);
        printf("Posição %d: %d\n", i, val);
    }
}

// Função para pausar até o usuário apertar Enter e depois limpar a tela
void pausar_elimpar() {
    printf("\nPressione Enter para continuar...");
    getchar(); // limpa o '\n' pendente do scanf
    getchar(); // espera o Enter real

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    Lista l;
    criar_lista(&l);

    int opcao, pos, valor;

    do {
        // Limpa a tela antes de mostrar o menu (na primeira volta, tela limpa)
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        printf("\n===== MENU =====\n");
        printf("1. Verificar se a lista está vazia\n");
        printf("2. Verificar se a lista está cheia\n");
        printf("3. Obter o tamanho da lista\n");
        printf("4. Obter valor de uma posição\n");
        printf("5. Modificar valor de uma posição\n");
        printf("6. Inserir elemento em uma posição\n");
        printf("7. Remover elemento de uma posição\n");
        printf("8. Exibir a lista\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (lista_vazia(&l))
                    printf("A lista está vazia.\n");
                else
                    printf("A lista NÃO está vazia.\n");
                pausar_elimpar();
                break;

            case 2:
                if (lista_cheia(&l))
                    printf("A lista está cheia.\n");
                else
                    printf("A lista NÃO está cheia.\n");
                pausar_elimpar();
                break;

            case 3:
                printf("Tamanho da lista: %d\n", obter_tamanho(&l));
                pausar_elimpar();
                break;

            case 4:
                printf("Digite a posição que deseja acessar: ");
                scanf("%d", &pos);
                if (obter_elemento(&l, pos, &valor))
                    printf("Valor na posição %d: %d\n", pos, valor);
                else
                    printf("Posição inválida.\n");
                pausar_elimpar();
                break;

            case 5:
                printf("Digite a posição que deseja modificar: ");
                scanf("%d", &pos);
                printf("Digite o novo valor: ");
                scanf("%d", &valor);
                if (modificar_elemento(&l, pos, valor))
                    printf("Valor modificado com sucesso!\n");
                else
                    printf("Erro: posição inválida.\n");
                pausar_elimpar();
                break;

            case 6:
                printf("Digite a posição onde deseja inserir: ");
                scanf("%d", &pos);
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                if (inserir_elemento(&l, pos, valor))
                    printf("Valor inserido com sucesso!\n");
                else
                    printf("Erro: posição inválida ou lista cheia.\n");
                pausar_elimpar();
                break;

            case 7:
                printf("Digite a posição que deseja remover: ");
                scanf("%d", &pos);
                if (remover_elemento(&l, pos))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro: posição inválida ou lista vazia.\n");
                pausar_elimpar();
                break;

            case 8:
                exibir_lista(&l);
                pausar_elimpar();
                break;

            case 9:
                printf("Encerrando programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
                pausar_elimpar();
        }
    } while (opcao != 9);

    return 0;
}
