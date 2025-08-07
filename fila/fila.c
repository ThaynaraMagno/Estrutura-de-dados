#include "fila.h"

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

int esta_vazia(Fila *f) {
    return f->quantidade == 0;
}

int esta_cheia(Fila *f) {
    return f->quantidade == MAX;
}

int enfileirar(Fila *f, int valor) {
    if (esta_cheia(f))
        return 0;

    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->quantidade++;
    return 1;
}

int desenfileirar(Fila *f, int *removido) {
    if (esta_vazia(f))
        return 0;

    *removido = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->quantidade--;
    return 1;
}

int frente(Fila *f, int *valor) {
    if (esta_vazia(f))
        return 0;

    *valor = f->dados[f->inicio];
    return 1;
}
