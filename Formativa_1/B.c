#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

void insere_inicio (celula *le, int x){
    celula *novaCelula = (celula*)malloc(sizeof(celula));
    novaCelula->dado = x; //insere dado da nova celula
    novaCelula->prox = le->prox; //faz a nova celula apontar para a cabeca
    le->prox = novaCelula; //faz a nova celula ser a cabeca
}

void insere_antes (celula *le, int x, int y){
    celula *aux = le;
    celula *atual = le->prox;

    celula *novaCelula = (celula*)malloc(sizeof(celula));

    //Responsável por percorrer a lista até chegar no final, ou até encontrar o elemento y
    while(atual != NULL && atual->dado != y){
        aux = atual;
        atual = atual->prox;
    }
    //Inserir no final da Lista
    if(atual == NULL){
        novaCelula->dado = x; //insere o dado da celula
        novaCelula->prox = NULL; //faz ela apontar para NULL, logo e a ultima
        aux->prox = novaCelula; // a celula auxiliar, que e a atual, aponta para a nova
    }
    //Inserir antes de y
    else{
        novaCelula->dado = x; //insere o dado
        novaCelula->prox = atual; //faz a nova celula apontar para a celula que contem o y, logo, antes dela
        aux->prox = novaCelula; //faz a atual apontar para a nova celula
    }
}
