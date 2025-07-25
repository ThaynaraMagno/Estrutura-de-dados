#include "lista.h"

void criar_lista(Lista *l) {
    l->tamanho = 0;
}

int lista_vazia(Lista *l) {
    return l->tamanho == 0;
}

int lista_cheia(Lista *l) {
    return l->tamanho == MAX;
}

int obter_tamanho(Lista *l) {
    return l->tamanho;
}

int obter_elemento(Lista *l, int pos, int *valor) {
    if (pos < 1 || pos > l->tamanho) return 0;
    *valor = l->dados[pos - 1];
    return 1;
}

int modificar_elemento(Lista *l, int pos, int novo_valor) {
    if (pos < 1 || pos > l->tamanho) return 0;
    l->dados[pos - 1] = novo_valor;
    return 1;
}

int inserir_elemento(Lista *l, int pos, int valor) {
    if (lista_cheia(l) || pos < 1 || pos > l->tamanho + 1) return 0;
    for (int i = l->tamanho; i >= pos; i--) {
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[pos - 1] = valor;
    l->tamanho++;
    return 1;
}

int remover_elemento(Lista *l, int pos) {
    if (lista_vazia(l) || pos < 1 || pos > l->tamanho) return 0;
    for (int i = pos - 1; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--;
    return 1;
}
