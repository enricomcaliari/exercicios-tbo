#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

typedef struct node Node;

struct node
{
    int chave;
    Node *esquerda;
    Node *direita;
};

struct arvore
{
    Node *raiz;
};

Arvore *inicializaArvore()
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

static Node *insereNode(Node *node, int chave)
{
    if (node == NULL)
    {
        Node *novo = (Node *)malloc(sizeof(Node));
        novo->chave = chave;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else if (chave < node->chave)
    {
        node->esquerda = insereNode(node->esquerda, chave);
    }
    else if (chave > node->chave)
    {
        node->direita = insereNode(node->direita, chave);
    }

    return node;
}

void adicionaChaveArvore(Arvore *arvore, int chave)
{
    arvore->raiz = insereNode(arvore->raiz, chave);
}

static int alturaNode(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }

    int esq = alturaNode(node->esquerda);
    int dir = alturaNode(node->direita);

    if (esq > dir)
    {
        return esq + 1;
    }
    else
    {
        return dir + 1;
    }
}

int alturaArvore(Arvore *arvore)
{
    return alturaNode(arvore->raiz);
}

static void imprimeNode(Node *node)
{
    if (node == NULL)
    {
        return;
    }

    imprimeNode(node->esquerda);

    printf("%d ", node->chave);

    imprimeNode(node->direita);
}

void imprimeArvore(Arvore *arvore)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        printf("Arvore vazia\n");
        return;
    }

    imprimeNode(arvore->raiz);
    printf("\n");
}

static void liberaNode(Node *node)
{
    if (node == NULL)
        return;

    liberaNode(node->esquerda);
    liberaNode(node->direita);

    free(node);
}

void liberaArvore(Arvore *arvore)
{
    if (arvore == NULL)
        return;
    liberaNode(arvore->raiz);
    free(arvore);
}
