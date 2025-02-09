#include <stdio.h>
#include <stdlib.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

struct no* criarNo(int value) {
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->dado = value;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void pre_ordem (no *raiz){
    if (raiz == NULL)
        return;

    struct no* pilha[1000]; // Assumindo uma árvore com no máximo 1000 nós
    int topo = -1;

    pilha[++topo] = raiz;

    while (topo >= 0) {
        struct no* node = pilha[topo--];
        printf("%d ", node->dado);

        // Empilhe o nó da subárvore direita primeiro
        if (node->dir)
            pilha[++topo] = node->dir;

        // Empilhe o nó da subárvore esquerda
        if (node->esq)
            pilha[++topo] = node->esq;
    }
}

/*
int main() {
    struct no* raiz = criarNo(1);
    raiz->esq = criarNo(2);
    raiz->dir = criarNo(3);
    raiz->esq->esq = criarNo(4);
    raiz->esq->dir = criarNo(5);

    printf("Árvore binária em pré-ordem (iterativa):\n");
    pre_ordem(raiz);

    return 0;
}
*/