#ifndef bst_h
#define bst_h

typedef struct arvore Arvore;

Arvore *inicializaArvore();

void adicionaChaveArvore(Arvore *arvore, int chave);

int alturaArvore(Arvore *arvore);

void imprimeArvore(Arvore *arvore);

void liberaArvore(Arvore *arvore);

#endif