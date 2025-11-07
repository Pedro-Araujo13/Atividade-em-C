#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int numero;
    struct No* prox;

}No;

No* criarNo(int valor){
    No* novo = (No*)malloc(sizeof(No));
    if (!novo){
        printf("Erro de memoria.");
        exit(1);
    }
    novo->numero = valor;
    novo->prox = NULL;
    return novo;
}
void inserir(No** cabeca, int valor){
    No* novo = criarNo(valor);
    if(*cabeca == NULL){
        *cabeca = novo;
    }else{
        No* atual = *cabeca;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void mostrar(No* cabeca){
    No* atual = cabeca;
    while(atual != NULL){
        printf("%d ->", atual->numero);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void limpar(No* cabeca){
    No* atual = cabeca;
    while(atual){
        No* limpe = atual;
        atual = atual->prox;
        free(limpe);
    }
}
int main(){
    No* lista = NULL;
    int dado, valor;

    printf("Quantos elementos vai inserir?:");
    scanf("%d", &dado);

    for(int i=0; i<dado; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valor);
        inserir(&lista, valor);
    }
    printf("\nLista criada: \n");
    mostrar(lista);
    limpar(lista);
    return 0;
}