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

void pos_ordem (no *raiz){
    if (raiz == NULL)
        return;

    struct no* pilha[1000]; // Assumindo uma árvore com no máximo 1000 nós
    int topo = -1;

    struct no* ultimoDir = NULL;
    struct no* atual = raiz;

    while (topo >= 0 || atual != NULL) {
        // Empilhe todos os nós da subárvore esquerda
        while (atual != NULL) {
            pilha[++topo] = atual;
            atual = atual->esq;
        }

        // Verifique se o nó no topo da pilha tem uma subárvore direita não visitada
        if (pilha[topo]->dir != NULL && ultimoDir != pilha[topo]->dir) {
            // Avance para a subárvore direita
            atual = pilha[topo]->dir;
        } else {
            // Pop o nó do topo da pilha e imprima seu valor
            printf("%d ", pilha[topo]->dado);
            ultimoDir = pilha[topo--];
        }
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

    printf("Árvore binária em pós-ordem (iterativa):\n");
    pos_ordem(raiz);

    return 0;
}
*/