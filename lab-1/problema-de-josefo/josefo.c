#include <stdio.h>
#include <stdlib.h>
#include "josefo.h"

typedef struct celula Celula;

struct celula
{
    int valor;
    Celula *prox;
};

struct josefo
{
    Celula *prim;
    int N, M;
};

Josefo *inicializaJosefo(int N, int M)
{
    if (N <= 0 || M <= 0)
        return NULL;

    Josefo *josefo = (Josefo *)malloc(sizeof(Josefo));
    josefo->N = N;
    josefo->M = M;

    Celula *prim = (Celula *)malloc(sizeof(Celula));
    prim->valor = 1;
    prim->prox = prim;
    josefo->prim = prim;

    Celula *atual = prim;

    for (int i = 2; i <= N; i++)
    {
        Celula *nova = (Celula *)malloc(sizeof(Celula));
        nova->valor = i;
        nova->prox = prim;
        atual->prox = nova;
        atual = nova;
    }

    return josefo;
}

void elegeLider(Josefo *josefo)
{
    if (josefo == NULL || josefo->N <= 0 || josefo->prim == NULL)
        return;

    Celula *atual = josefo->prim;
    Celula *anterior = NULL;

    Celula *temp = josefo->prim;
    while (temp->prox != josefo->prim)
    {
        temp = temp->prox;
    }
    anterior = temp;

    while (atual != atual->prox)
    {
        for (int i = 0; i < josefo->M - 1; i++)
        {
            anterior = atual;
            atual = atual->prox;
        }

        anterior->prox = atual->prox;

        free(atual);

        atual = anterior->prox;
    }

    printf("\nLider: %d\n", atual->valor);

    josefo->prim = atual;
    free(josefo->prim);
    free(josefo);
}