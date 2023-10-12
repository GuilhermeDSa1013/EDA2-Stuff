#include <stdio.h>
#include <stdlib.h>

//Struct celula
typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

//Funcao para imprimir
void imprime (celula *le){
    struct celula *atual = le->prox;
    
    while (atual != NULL){
        printf("%d -> ", atual->dado);
        atual=atual->prox;
    }

    printf("NULL\n");
}

//Funcao para imprimir recursiva
void imprime_rec (celula *le){
    
    if (le == NULL || le->prox == NULL){
        printf("NULL\n");
        return;
    }

    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}

/*
int main(){
    celula *a = (celula *)malloc(sizeof(celula));
    celula *b = (celula *)malloc(sizeof(celula));
    celula *c = (celula *)malloc(sizeof(celula));

    a->dado = 1;
    b->dado = 2;
    c->dado = 3;

    a->prox = b;
    b->prox = c;
    c->prox = NULL;

    imprime(a);
    imprime_rec(a);

    free(a);
    free(b);
    free(c);

    return 0;
}
*/
