#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

//Remove a celula posterior a p
int remove_depois(celula *p) {  
  if (p == NULL || p->prox == NULL)
    return 0;
  celula *aux = p->prox; //Faz o auxiliar apontar para o proximo de p
  p->prox = aux->prox; 
  int x = aux->dado;
  free(aux); //a remocao e feita por um free
  return x;
}

//Remove uma celula que contenha o valor de x
void  remove_elemento (celula *le, int x){
  celula *anterior = le;

  //Vai ate o fim da lista ou ate achar x
  while (anterior->prox && anterior->prox->dado != x){
    anterior = anterior->prox;
  }
  
  //Quando acha
  if (anterior->prox){
    celula *aux = anterior->prox;
    anterior->prox = aux->prox; //faz o anterior apontar para a proxima celula dps da que vai remover
    free(aux); //remove
  }
}

//Remove todas as ocorrênias de x
void remove_todos_elementos (celula *le, int x){
  celula *anterior = le;
  celula *aux;
  
  while (anterior->prox) { //percorre até ser NULL o próximo
    if (anterior->prox->dado == x) { //caso encontre o dado
      aux = anterior->prox; //faz o auxiliar apontar para a celula atual
      anterior->prox = aux->prox; //pega o proximo do auxiliar
      free(aux);
    } else {
      anterior = anterior->prox; //caso n ache, continua seguindo
    }
  }
}
