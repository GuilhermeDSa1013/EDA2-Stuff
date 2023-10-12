#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *a = l1->prox, *b = l2->prox, *c = l3;

    while (a && b ) { //enquanto forem diferente de NULL
    
        /*celula *menor;
        if (a->dado < b->dado) {
            //guarda e avança para o próximo
            menor = a; 
            a = a->prox;
        } else {
            //guarda e avança para o próximo
            menor = b;
            b = b->prox;
        }
        
        //escreve na nova lista já em ordem
        c->prox = menor;
        //e avança para o próximo
        c = c->prox;
    }*/

    //Faz a mesma coisa porém mais otimizado, poiso por algum motivo dá time limit exceeded, mas segue a lógica anterior
    celula **menor = (a->dado < b->dado) ? &a : &b;
    c->prox = *menor;
    *menor = (*menor)->prox;
    c = c->prox;
    }
    
    /*if (a != NULL) {
        c->prox = a;
    } else {
        c->prox = b;
    }*/
    
    //tentando otimizar o if
    c->prox = a ? a : b;
}