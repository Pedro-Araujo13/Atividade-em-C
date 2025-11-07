#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define SIZE 5
#define LEN 50

typedef struct {
    int topo, total;
    char elem[SIZE][LEN];
}Pilha;

void criarFila (Pilha *p){
    p->topo = -1;
    p->total = SIZE;
}

int vazia(Pilha *p){
    return (p->topo == -1);
}


int cheia(Pilha *p){
    return (p->topo == p->total - 1);
}

void empilhar (Pilha *p, char *dado){
    if(!cheia(p)){
        p->topo++;
        strcpy(p->elem[p->topo], dado);
    } else{
        printf("\nAs caixas ja estão no limte \n");
    }
}

void desempilhar(Pilha *p){
    if(!vazia(p)){
        printf("\n %s desempilhado\n", p->elem[p->topo]);
        p->topo--;
        return;
    }
    printf("\nNão ha caixas para desenfileirar\n");
        return;
}

void listar(Pilha *p){
    if (vazia(p)){
        printf("\nNao ha caixas para listar!\n");
        return;
    } 

    for (int i = p->topo; i>=0; i--){
        printf("\n%s\n", p->elem[i]);
    }
}

void mostrarTopo(Pilha *p){
    if(!vazia(p)){
        printf("Topo: %s\n", p->elem[p->topo]);
        return;
    }
    printf("\nNao ha caixas!\n");
    return;
    
}

int main(){
    Pilha novaPilha;
    int opcao;
    char valor[LEN];
 
    criarFila(&novaPilha);
    do{
        printf("\n=== Central de Caixas ===");
        printf("\n1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Listar \n");
        printf("4 - Mostrar Topo \n");
        printf("5 - Sair \n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
    
        switch (opcao){
            case 1:
                printf("\nNome Caixa: ");
                scanf(" %s", valor);
                empilhar(&novaPilha, valor);
                break;
            case 2:
                desempilhar(&novaPilha);
                
                break;

            case 3:
                listar(&novaPilha);
                break;
            case 4:
                mostrarTopo(&novaPilha);
                break;
            case 5:
                printf("Saindo do sistema");
                break;
            
            default:
                printf("Opcao invalida");
        }
        
    }while(opcao != 5);
    return 0;

    
}