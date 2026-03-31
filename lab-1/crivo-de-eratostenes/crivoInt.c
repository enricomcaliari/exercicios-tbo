#include <stdio.h>
#include <stdlib.h>
#include "crivoInt.h"

struct crivo
{
    int *lista;
    int n;
};

Crivo *inicializaCrivo(int n)
{
    Crivo *crivo = (Crivo *)malloc(sizeof(Crivo));
    crivo->lista = (int *)malloc((n + 1) * sizeof(int));
    crivo->n = n;

    crivo->lista[0] = 0;
    crivo->lista[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        crivo->lista[i] = 1;
    }

    return crivo;
}

void marcaNaoPrimos(Crivo *crivo)
{
    for (int i = 2; i <= crivo->n; i++)
    {
        if (crivo->lista[i] == 1)
        {
            for (int j = i + i; j <= crivo->n; j += i)
            {
                crivo->lista[j] = 0;
            }
        }
    }
}

void imprimeCrivo(Crivo *crivo)
{
    printf("crivoInt\n");
    for (int i = 0; i <= crivo->n; i++)
    {
        if (crivo->lista[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void liberaCrivo(Crivo *crivo)
{
    free(crivo->lista);
    free(crivo);
}