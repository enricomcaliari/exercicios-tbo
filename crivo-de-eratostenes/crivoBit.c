#include <stdio.h>
#include <stdlib.h>
#include "crivoBit.h"

struct crivo
{
    unsigned char *lista;
    int n;
};

Crivo *inicializaCrivo(int n)
{
    Crivo *crivo = (Crivo *)malloc(sizeof(Crivo));
    
    crivo->lista = (unsigned char *)calloc((n / 8) + 1, sizeof(unsigned char));
    crivo->n = n;

    for (int i = 2; i <= n; i++)
    {
        crivo->lista[i / 8] |= (1 << (i % 8)); 
    }

    return crivo;
}

void marcaNaoPrimos(Crivo *crivo)
{
    for (int i = 2; i <= crivo->n; i++)
    {
        if (crivo->lista[i / 8] & (1 << (i % 8)))
        {
            for (int j = i + i; j <= crivo->n; j += i)
            {
                crivo->lista[j / 8] &= ~(1 << (j % 8));
            }
        }
    }
}

void imprimeCrivo(Crivo *crivo)
{
    printf("crivoBit\n");
    for (int i = 0; i <= crivo->n; i++)
    {
        if (crivo->lista[i / 8] & (1 << (i % 8)))
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