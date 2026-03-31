#include <stdio.h>
#include "bst.h"

int main()
{
    Arvore *arvore = inicializaArvore();

    int n;
    scanf("%d", &n);

    int chave;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &chave);
        adicionaChaveArvore(arvore, chave);
    }

    imprimeArvore(arvore);
    liberaArvore(arvore);

    return 0;
}