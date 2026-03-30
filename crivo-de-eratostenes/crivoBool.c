#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "crivoBool.h"

struct crivo
{
    bool *lista;
    int n;
};

Crivo *inicializaCrivo(int n)
{
    Crivo *crivo = (Crivo *)malloc(sizeof(Crivo));
    crivo->lista = (bool *)malloc((n + 1) * sizeof(bool));
    crivo->n = n;

    crivo->lista[0] = false;
    crivo->lista[1] = false;
    for (int i = 2; i <= n; i++)
    {
        crivo->lista[i] = true;
    }

    return crivo;
}

void marcaNaoPrimos(Crivo *crivo)
{
    for (int i = 2; i <= crivo->n; i++)
    {
        if (crivo->lista[i])
        {
            for (int j = i + i; j <= crivo->n; j += i)
            {
                crivo->lista[j] = false;
            }
        }
    }
}

void imprimeCrivo(Crivo *crivo)
{
    printf("crivoBool\n");
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