#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct{
    int itens[TAM];
    int inicio;
    int fim;
}Fila;

void criar(Fila *f){
    f->inicio = 0;
    f->fim = -1;
}
int filaCheia(Fila *f){
    return f->fim == TAM -1;
}
int filaVazia(Fila *f){
    return f->inicio > f->fim;
}
void enfileirar(Fila *f, int valor){
    if(filaCheia(f)){
        printf("Fila Cheia! Não podemos enfileirar!");
    } else{
        f->fim++;
        f->itens[f->fim]=valor;
        printf("O numero %d entrou na fila", valor);
    }
}
int desenfileirar(Fila *f){
    if(filaVazia(f)){
        printf("Fila Vazia! Não podemos desenfileirar");
        return -1;
    }else{
        int removido = f->itens[f->inicio];
        f->inicio++;
        printf("O numero %d foi removido da fila", removido);
        return removido;
    }
    }
void exibir(Fila *f){
    if(filaVazia(f)){
        printf("Fila vazia\n");
    }else{
        printf("Fila: ");
        for(int i = f->inicio; i<= f->fim; i++){
            printf("%d - ", f->itens[i]);
        }
        printf("\n");
    }
}
int main(void){
    Fila f;
    criar(&f);
    int opcao, valor;

    do{
        printf("\n1- Enfileirar (inserir)\n");
        printf("2- Desenfileirar (remover)\n");
        printf("3- Exibir fila \n");
        printf("0- Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Digite um numero para enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&f, valor);
                break;
            case 2:
                desenfileirar(&f);
                break;
            case 3:
                exibir(&f);
                break;
            case 0:
                printf("Saindo do sistema!");
            default:
                printf("Opcao inválida\n");
        }
    }while(opcao != 0);
    return 0;
}
