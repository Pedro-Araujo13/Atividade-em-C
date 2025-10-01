#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    char nome[30];
    struct No* prox;

}No;

// Criar
No* criar(const char *texto){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo){
        printf("Erro de memória"); // por que se (!novo)=True ou seja, Não novo, vai dar erro de memória?
        exit(1);
    }
    strncpy(novo->nome, texto, sizeof(novo->nome)); // ?? strncpy -> copia o nome do input do usuário
    novo->nome[sizeof(novo->nome)-1]='\0';
    novo->prox = NULL;
    return novo;
}

// Adicionar
void inserir(No** cabeca, const char *texto){
    No* novo = criar(texto);
    if(*cabeca == NULL){
        *cabeca = novo;
        
    }else{
        No* atual = *cabeca;
        while(atual->prox !=NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    printf("Cadastro Efetuado!");
}
// Remover
int remover(No** cabeca, const char *alvo_rem){
    No *atual = *cabeca, *anterior = NULL;
    while(atual && strcmp(atual->nome, alvo_rem) != 0){
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
        printf("Lista Vazia. \n");
        return;
    }
    for(No* dado = cabeca; dado != NULL; dado = dado->prox){
        printf("[%s]->", dado->nome);
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
    char nome[30];

    while(opcao != 0){
        puts("--- Lista de Nomes ----");
        puts("1) Cadastrar Nomes ");
        puts("2) Lista nomes ");
        puts("3) Remover nome ");
        puts("0) Sair ");
        printf("Opcao: ");
        if(scanf("%d", &opcao)!=1){
            puts("Entrada invállida. ");
            break;
        }
        getchar();
        switch(opcao){
            case 1:
                printf("Nome do participante: ");
                if(scanf("%29[^\n]", nome) != 1){
                    puts("Entrada inválida");
                    break;
                }
               getchar();
               inserir(&lista, nome);
               puts("Cadastrado");
               break;

            case 2:
            listar(lista);
            break;
                

            case 3:
                printf("Nome a ser removido: ");
                if(scanf("%29[^\n]", nome)!= 1){
                    puts("Entrada invalida");
                    break;
                }
                getchar();
                if(remover(&lista, nome)){
                    puts("Nome removido!");
                }else{
                    puts("Nome não encontrado!");
                }
                break;
            case 0:
                puts("Encerrado");
                break;
            default:
                puts("Opcao invalida");
                break;
        }

    }
        limpar(lista);
        return 0;


}

//Contexto: Registrar participantes que entram e saem ao longo do evento.
//Objetivo: Inserir pessoas, remover pelo nome, buscar por nome, imprimir a lista.

