#ifndef LISTA_H
#define LISTA_H

#define MAX 100

typedef struct {
    int dados[MAX];
    int tamanho;
} Lista;

void criar_lista(Lista *l);
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
int obter_tamanho(Lista *l);
int obter_elemento(Lista *l, int pos, int *valor);
int modificar_elemento(Lista *l, int pos, int novo_valor);
int inserir_elemento(Lista *l, int pos, int valor);
int remover_elemento(Lista *l, int pos);

#endif
