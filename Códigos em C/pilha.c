    #include <stdio.h>
    #include <unistd.h>

    #define TAM 5

    typedef struct{
        int topo, total;
        float elem[TAM];

    }Pilha;

    void criar(Pilha *p){
        p->topo = -1;
        p->total = TAM;
    }

    int vazia(Pilha *p){
        return (p->topo == -1);
    }

    int cheia(Pilha *p){
        return(p->topo == p->total - 1);
    }

    void empilhar (Pilha *p, float dado){
        if(!cheia(p)){
            p->topo++;
            p->elem[p->topo] = dado;
        }else{
            printf("\n Pilha Cheia \n");
        }
    }
    float desempilhar(Pilha *p){
        if(!vazia(p)){
            float aux = p->elem[p->topo];
            p->topo--;
            return aux;
        }
        printf("\n Pilha Vazia");
        return -1;
    }

    float mostrarTopo(Pilha *p){
        if(!vazia(p)){
            return p->elem[p->topo];
        }
        printf("\n Pilha Vazia");
        return -1;
    }

    int main(){
        Pilha novaPilha;
        int opcao;
        float valor;
        criar(&novaPilha);

        do{
            printf("\n 1. Empilhar \n");
            printf("\n 2. Desempilhar \n");
            printf("\n 3. Mostrar o topo \n");
            printf("\n 4. Sair \n");
            printf("\n Opcao: ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                    printf("\n Digite um número: ");
                    scanf("%f", &valor);
                    empilhar(&novaPilha, valor);
                    break;
                case 2:
                    valor = desempilhar(&novaPilha);
                    if(valor != -1){
                    printf("\n %.1f desempilhado\n", valor);
                }
                    break;

                case 3:
                    valor = mostrarTopo(&novaPilha);
                    if(valor != -1){
                        printf("\n Topo: %.1f", valor);
                    }
                    break;

                case 4:
                    printf("\n Saindo do Sistema...");
                    break;

                default:
                    printf("Opcao Invalida!");

            }
        }while(opcao != 4);
        return 0;
    }