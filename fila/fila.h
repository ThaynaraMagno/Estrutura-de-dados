#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int quantidade;
} Fila;

// Inicializa os campos da fila
void inicializar(Fila *f);

// Retorna 1 se a fila estiver vazia, 0 caso contrário
int esta_vazia(Fila *f);

// Retorna 1 se a fila estiver cheia, 0 caso contrário
int esta_cheia(Fila *f);

// Insere um valor no final da fila (retorna 1 se conseguir, 0 se estiver cheia)
int enfileirar(Fila *f, int valor);

// Remove um valor do início da fila (retorna 1 se conseguir, 0 se estiver vazia)
int desenfileirar(Fila *f, int *removido);

// Consulta o valor do início da fila sem remover (retorna 1 se conseguir, 0 se estiver vazia)
int frente(Fila *f, int *valor);

#endif
