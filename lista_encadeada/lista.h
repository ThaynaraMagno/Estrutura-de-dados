#ifndef LISTA_H
#define LISTA_H

// Nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Lista em si
typedef struct {
    No* inicio;
    int tamanho;
} Lista;

// Funções principais
void criarLista(Lista* l);
int estaVazia(Lista* l);
int tamanhoLista(Lista* l);
int acessarValor(Lista* l, int pos, int* val);
int alterarValor(Lista* l, int pos, int novoValor);
int inserirNaPosicao(Lista* l, int pos, int valor);
int removerNaPosicao(Lista* l, int pos, int* val);
void imprimirLista(Lista* l);
void liberarLista(Lista* l);

#endif
