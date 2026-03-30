#include <stdio.h>
#include "crivoBit.h"

int main()
{
    int n;
    scanf("%d", &n);

    Crivo *crivo = inicializaCrivo(n);

    marcaNaoPrimos(crivo);

    imprimeCrivo(crivo);

    liberaCrivo(crivo);

    return 0;
}