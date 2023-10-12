#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
  celula *atual = le->prox;

  while (atual != NULL){//percorre a lista
    //caso ache retorna a celula atual
    if(atual->dado == x) 
    return atual;
    atual = atual->prox;
  }
}

celula *busca_rec(celula *le, int x) {
    //percorre a lista até o final ou até encontrar o elemento
  if (le == NULL || le->dado == x) {
    return le;
  }
  //chama de novo a mesma função, mas agora passando a proxima celula
  return busca_rec(le->prox, x);
}