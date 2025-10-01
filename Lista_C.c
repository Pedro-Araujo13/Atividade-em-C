#include <stdio.h>
#include <stdlib.h>

struct No{
    int numero;
    struct No* prox;
};


int main(){
   struct No* primeiro = (struct No*)malloc(sizeof(struct No));
   struct No* segundo = (struct No*)malloc(sizeof(struct No));
   struct No* terceiro = (struct No*)malloc(sizeof(struct No));

   primeiro->numero = 10;
   segundo->numero = 30;
   terceiro->numero = 50;

   primeiro->prox = segundo;
   segundo->prox = terceiro;
   terceiro->prox = NULL;

   struct No* atual = primeiro;
   while(atual != NULL){
        printf("%d -> ", atual->numero);
        atual = atual->prox;
   }
   printf("NULL\n");
   return 0;
}