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

void em_ordem (no *raiz){
    if (raiz == NULL)
        return;

    struct no* pilha[1000]; // Assumindo uma árvore com no máximo 1000 nós
    int topo = -1;

    struct no* noAtual = raiz;

    while (topo >= 0 || noAtual != NULL) {

        // Empilhe todos os nós da subárvore esquerda
        while (noAtual != NULL) {
            pilha[++topo] = noAtual;
            noAtual = noAtual->esq;
        }

        // Pop o nó do topoo da pilha e imprima seu valor
        noAtual = pilha[topo--];
        printf("%d ", noAtual->dado);

        // Avance para a subárvore direita
        noAtual = noAtual->dir;
    }
}

/*
int main() {
    struct no* raiz = criarNo(1);
    raiz->esq = criarNo(2);
    raiz->dir = criarNo(3);
    raiz->esq->esq = criarNo(4);
    raiz->esq->dir = criarNo(5);
    raiz->dir->esq = criarNo(6);
    raiz->dir->dir = criarNo(7);

    printf("Árvore binária em em-ordem (iterativa):\n");
    em_ordem(raiz);

    return 0;
}
*/