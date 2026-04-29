#include <stdio.h>
#include "josefo.h"

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    Josefo *josefo = inicializaJosefo(N, M);
    elegeLider(josefo);

    return 0;
}