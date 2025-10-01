#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char produto[30];
    int qtd;
    struct No* prox;

}No;

//Criar Lista
No* criar(const char *texto){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo){
        printf("Erro de memória"); 
        exit(1);
    }
    strncpy(novo->produto, texto, sizeof(novo->produto));
    novo->produto[sizeof(novo->produto)-1] = '\0';
    novo->prox = NULL;
    return novo;
}

void inserir(No** cabeca, const char *texto){
    No* novo = criar(texto);
    No *atual = *cabeca;

    while (atual != NULL){
        if (strcmp (atual->produto, texto)== 0 ){
            atual->qtd++;
            return;
        }
        atual = atual->prox;
    }

    if(*cabeca == NULL){
        *cabeca = novo;
    }
    else{
        No* atual = *cabeca;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

int remover(No** cabeca, const char *alvo_rem){
    No *atual = *cabeca, *anterior = NULL;
    while(atual && strcmp(atual->produto, alvo_rem) != 0){
        anterior = atual;
        atual = atual->prox;
    }
    if(!atual) return 0;
    if(!anterior) *cabeca = atual->prox;
    else anterior->prox = atual->prox;
    free(atual);
    return 1;
}

void listar(No* cabeca){
    if(!cabeca){
        printf("Lista vazia.\n");
        return;
    }
    No *atual = cabeca;
    while (atual != NULL){
        printf("[%s %d]->", atual->produto, atual->qtd+1);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void limpar(No* cabeca){
    while(cabeca){
        No* prox = cabeca->prox;
        free(cabeca);
        cabeca = prox;
    }
}
int main(void){
    No* lista = NULL;
    int opcao = -1;
    char produto[30];

    while(opcao != 0){
        puts("### Lista de Compras ### \n1. Registrar itens \n2. Listar Itens \n3. Remover Item \n0. Sair\n");
        printf("Opcao: ");
        if(scanf("%d", &opcao)!=1){
            puts("Entrada inválida. ");
            break;
        }
        getchar();
        switch(opcao){
            case 1:
                printf("Item: ");
                if(scanf("%29[^\n]", produto) !=1){
                    puts("Entrada inválida");
                    break;
                }
                getchar();
                inserir(&lista, produto);
                puts("Item registrado!");
                break;
            case 2:
            listar(lista);
            break;

            case 3:
                printf("Nome a ser removido: ");
                if(scanf("%29[^\n]", produto)!= 1){
                    puts("Entrada inválida");
                    break;
                }
                getchar();
                if(remover(&lista, produto)){
                    puts("Item removido!");
                }else{
                    puts("Item não encontrado");
                }
                break;
            case 0:
                puts("Encerrando");
                break;
            default:
                puts("Opcao inválida");
                break;
        }
    }
        limpar(lista);
        return 0;
}