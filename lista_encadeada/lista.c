#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void criarLista(Lista* l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

int estaVazia(Lista* l) {
    return l->tamanho == 0;
}

int tamanhoLista(Lista* l) {
    return l->tamanho;
}

int acessarValor(Lista* l, int pos, int* val) {
    if (pos < 1 || pos > l->tamanho) return 0;

    No* atual = l->inicio;
    for (int i = 1; i < pos; i++)
        atual = atual->prox;

    *val = atual->valor;
    return 1;
}

int alterarValor(Lista* l, int pos, int novoValor) {
    if (pos < 1 || pos > l->tamanho) return 0;

    No* atual = l->inicio;
    for (int i = 1; i < pos; i++)
        atual = atual->prox;

    atual->valor = novoValor;
    return 1;
}

int inserirNaPosicao(Lista* l, int pos, int valor) {
    if (pos < 1 || pos > l->tamanho + 1) return 0;

    No* novo = (No*)malloc(sizeof(No));
    if (!novo) return 0;

    novo->valor = valor;

    if (pos == 1) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        No* atual = l->inicio;
        for (int i = 1; i < pos - 1; i++)
            atual = atual->prox;

        novo->prox = atual->prox;
        atual->prox = novo;
    }

    l->tamanho++;
    return 1;
}

int removerNaPosicao(Lista* l, int pos, int* val) {
    if (pos < 1 || pos > l->tamanho) return 0;

    No* removido;

    if (pos == 1) {
        removido = l->inicio;
        l->inicio = removido->prox;
    } else {
        No* anterior = l->inicio;
        for (int i = 1; i < pos - 1; i++)
            anterior = anterior->prox;

        removido = anterior->prox;
        anterior->prox = removido->prox;
    }

    *val = removido->valor;
    free(removido);
    l->tamanho--;
    return 1;
}

void imprimirLista(Lista* l) {
    No* atual = l->inicio;

    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void liberarLista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
    l->tamanho = 0;
}
