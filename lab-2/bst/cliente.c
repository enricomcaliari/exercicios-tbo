#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main()
{
    Arvore *arvore = inicializaArvore();

    int n;
    scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        adicionaChaveArvore(arvore, rand());
    }

    printf("Altura da arvore: %d\n", alturaArvore(arvore));

    liberaArvore(arvore);

    return 0;
}