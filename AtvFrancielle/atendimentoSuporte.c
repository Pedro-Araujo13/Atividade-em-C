#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define MAX 5

typedef struct {
    char nomes[MAX][TAM];
    int tamanho, tras, frente;
}Fila;

void criarFila(Fila *f){
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}
int filaCheia(Fila *f){
    return f->tamanho == MAX;
}
int filaVazia(Fila *f){
    return f->tamanho == 0;
}

void entrar(Fila *f, char *valor){
    if (filaCheia(f)){
        printf("A fila está cheia, aguarde alguém ser atendido!\n");
    }else{
        strcpy(f->nomes[f->tras], valor);
        f->tras = (f->tras + 1) % MAX;
        f->tamanho++;
        printf("%s entrou na fila.\n", valor);
    }
}

int atender(Fila *f, char *atendido){
    if (filaVazia(f)){
        printf("Todos os clientes já foram atendidos.\n");
        return -1;
    } else{

        strcpy(atendido, f->nomes[f->frente]);
        f->frente = (f->frente + 1) % MAX;
        f->tamanho--;
        printf("%s foi atendido.\n", atendido);
        return 0;
    }
}

void listar(Fila *f){
    if (filaVazia(f)){
        printf("Não há clientes para listar.\n");

    }else{
        printf("Fila: ");
        int i = f->frente;
        for (int j = 0; j < f->tamanho; j++){
            printf("%s -> ", f->nomes[i]);
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

int main(void){
    Fila f;
    criarFila(&f);

    int opcao;
    char valor[TAM], atendido[TAM];

    do{
        printf("\n=== MENU DA FILA ===\n");
        printf("1 - Entrar na fila\n");
        printf("2 - Atender\n");
        printf("3 - Listar\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("Insira seu nome para entrar na fila: ");
                scanf(" %s", valor);
                entrar(&f, valor);
                break;
            case 2:
                atender(&f, atendido);
                break;
            case 3:
                listar(&f);
                break;
            case 0:
                printf("Saindo do programa...");
                break;
            default:
                printf("Opcao Invalida!\n");
        }
    }while(opcao != 0);
    
    return 0;
}