//FILA CIRCULAR

#include <stdio.h>
#include <stdlib.h>

#define TAM 5 

typedef struct {
    int itens[TAM];
    int frente;
    int tras;
    int tamanho; 
} Fila;

void inicializaFila(Fila *f) {
    f->frente = 0;
    f->tras = TAM - 1;
    f->tamanho = 0; 
}
int filaCheia(Fila *f) {
    return f->tamanho == TAM; 
}
int filaVazia(Fila *f) {
    return f->tamanho == 0; 
}

void enfileirar(Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível enfileirar %d.\n", valor);
    } else {
        f->tras = (f->tras + 1) % TAM; 
        f->itens[f->tras] = valor;
        f->tamanho++;  
        printf("%d entrou na fila.\n", valor);
    }
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nada a desenfileirar.\n");
        return -1;
    } else {
        int removido = f->itens[f->frente];
        f->frente = (f->frente + 1) % TAM; 
        f->tamanho--;  
        printf("%d saiu da fila.\n", removido);
        return removido;
    }
}

void exibirFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
    } else {
        printf("Fila: ");
        int i = f->frente;
        for (int j = 0; j < f->tamanho; j++) {  
            printf("%d ", f->itens[i]);
            i = (i + 1) % TAM; 
        }
        printf("\n");
    }
}

int main(void) {
    Fila f;
    inicializaFila(&f);

    int opcao, valor;

    do {
        printf("\n=== MENU DA FILA ===\n");
        printf("1 - Enfileirar (inserir)\n");
        printf("2 - Desenfileirar (remover)\n");
        printf("3 - Exibir fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número para enfileirar: ");
                scanf("%d", &valor);
                enfileirar(&f, valor);
                break;

            case 2:
                desenfileirar(&f);
                break;

            case 3:
                exibirFila(&f);
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
