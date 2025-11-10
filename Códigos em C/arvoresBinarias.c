#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
   struct No* esq;
   struct No* dir;
}No;

No* criar(int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo != NULL){
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

No* inserir(No* raiz, int valor){
    if(raiz == NULL){
        raiz = criar(valor);
    }
    else{
        if(valor < raiz->valor){
            raiz->esq = inserir(raiz->esq, valor);
        }
        else if(valor > raiz->valor){
            raiz->dir = inserir(raiz->dir, valor);
        }
    }
    return raiz;
}

void mostrar(No* raiz, int nivel){
    int i;
    if(raiz != NULL){
        mostrar(raiz->dir, nivel + 1);
        for(i = 0; i<nivel; i++){
            printf("    ");
        }
        printf("%d\n", raiz->valor);
        mostrar(raiz->esq, nivel + 1);
    }
}

void limpar(No* raiz){
    if (raiz != NULL){
        limpar(raiz->dir);
        limpar(raiz->esq);
        free(raiz);
    }
}

No* remover(No* raiz, int valor){
    if (raiz == NULL){
        return NULL;
    }
    if(valor < raiz->valor){
        raiz->esq = remover(raiz->esq, valor);

    }
    else if(valor > raiz->valor){
        raiz->dir = remover(raiz->dir, valor);
    }
    else{
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }
    else if(raiz->esq == NULL){
        No* elem = raiz->dir;
        free(raiz);
        return elem;
    }
    else if(raiz->dir == NULL){
        No* elem = raiz->esq;
        free(raiz);
        return elem;
    }
    else{
        No*elem = raiz->dir;
        while(elem->esq != NULL){
            elem = elem->esq;
        }
        raiz->valor = elem->valor;
        raiz->dir = remover(raiz->dir, elem->valor);

        }
    }
    return raiz;
}
int main(){
    No* raiz = NULL;
    int valor;
    printf("Digite valores para construir a arvore e (-1 para encerrar): ");
    while(1){
        printf("\nValor: ");
        scanf("%d", &valor);
        if(valor == -1){
            break;
        }
        raiz = inserir(raiz, valor);
    }
    printf("Arvore inicial: \n");
    mostrar(raiz, 0);

    while(1){
        printf("Digite um valor para remover: (-1 para encerrar): ");
        scanf("%d", &valor);
        if(valor == -1){
            break;
        }
        raiz = remover(raiz, valor);
        printf("Arvore apos remover valor %d\n", valor);
        mostrar(raiz,0);
    }
    limpar(raiz);
    return 0;
}