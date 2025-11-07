#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    char id[9];
    struct No* prox;
   
}No;

// Criar Lista
No* criar(const char *numero_id){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo){
        printf("Erro de memória");
        exit(1);
    }
    strncpy(novo->id, numero_id, sizeof(novo->id));
    novo->id[sizeof(novo->id)-1] = '\0';
    novo->prox = NULL;
    return novo;
}

//Cadastrar ID do pedido
void cadastrar(No** cabeca, const char *numero_id){
    No* novo = criar(numero_id);
    if(*cabeca == NULL){
        *cabeca = novo;
    }else{
        No* atual = *cabeca;
        while(atual->prox !=NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

//definir como entregue
int entregue(No** cabeca, const char *pedido_entregue){
    No *atual = *cabeca, *anterior = NULL;
    while(atual && strcmp(atual->id, pedido_entregue) != 0){
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
        printf("Nenhum Pedido a ser entregue, eba!\n");
        return;
    }
    for(No* dado = cabeca; dado != NULL; dado = dado->prox){
        printf("[%s]->", dado->id);
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
    char id[9];

    while(opcao !=0){
        puts("### ZÉ DELIVERY ###\n1) Cadastrar Pedido \n2) Listar Pedidos \n3) Marcar como Entregue \n0) Sair");
        printf("Opcao: ");
        if(scanf("%d", &opcao)!=1){
            puts("Entrada invália.");
            break;
        }
        getchar();
        switch(opcao){
            case 1:
                printf("ID do pedido(8 digitos): ");
                if(scanf("%8[^\n]", id) != 1){
                    puts("Entrada inválida!");
                    break;
                }
                getchar();
                cadastrar(&lista, id);
                puts("ID do pedido registrado!");
                break;
            case 2:
                listar(lista);
                break;

            case 3:
                printf("Digite o ID do pedido entregue: ");
                if (scanf("%8[^\n]", id)!= 1){
                    puts("Entrada invalida");
                    break;
                }
                getchar();
                if(entregue(&lista, id)){
                    puts("Pedido Entregue!");
                }else{
                    puts("ID não entcontrado!");
                }
                break;
            case 0:
                puts("Encerrado");
                break;
            default:
                puts("Opcao Invalida");
                break;
        }

    }
    limpar(lista);
    return 0;

}