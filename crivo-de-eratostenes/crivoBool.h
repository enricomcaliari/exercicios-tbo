#ifndef crivoBool_h
#define crivoBool_h

typedef struct crivo Crivo;

Crivo *inicializaCrivo(int n);

void marcaNaoPrimos(Crivo *crivo);

void imprimeCrivo(Crivo *crivo);

void liberaCrivo(Crivo *crivo);

#endif