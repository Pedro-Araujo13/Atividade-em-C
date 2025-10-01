#include <stdio.h>
#include <stdlib.h>



int main(){
    int opcao;
    char produto [50];
    char linha[256];
    int sair = 1;
    FILE *entrada = fopen("estoque.txt", "a+");
 
            if (entrada == NULL){
            printf("Erro ao abrir o arquivo!");
            return 1;
                                     }
while (sair != 0){
    printf("\nMenu: \n1. Cadastrar Produto \n2. Editar Produto \n3. Deletar Produto \n4. Listar Produto \n0. Sair \nEscolha uma opcao: ");
    scanf("%d", &opcao);
    if (opcao < 0 || opcao > 4){
        printf("Opcao Invalida!");
        return 1;

    }
    else{
    switch(opcao){
        case 1:
            printf("Escreva o produto que voce deseja inserir: ");
            scanf("%s", produto);
            fprintf(entrada, "%s\n", produto);
            fclose(entrada);
            printf("Produto cadastrado com sucesso!");
        
            break;
        case 2:
            int i, edicao;
            char novo_produto[50];
           

            printf("-Lista de Produtos-\n");

            while (fgets(linha, sizeof(linha), entrada) != NULL){
                printf("%d. %s",i+1, linha);
                i +=1;
                    }
                    
            FILE *arquivo_temp = fopen("arquivo_temp.txt", "w");
            if (arquivo_temp == NULL){
                printf("Erro ao tentar abrir arquivo!");
                return 1;
            }


            printf("\nInsira o valor o número que voce deseja editar: ");
            scanf("%d", &edicao);

            printf("\nInsira o novo produto: ");
            scanf("%s", novo_produto);

            rewind(entrada);
            int num_linha = 1;
            while (fgets(linha, sizeof(linha), entrada) != NULL){
                if(num_linha == edicao){
                    fprintf(arquivo_temp, "%s\n", novo_produto);
                }
                else{
                 fputs(linha, arquivo_temp);
                }
                num_linha++;
                
            }
            fclose(entrada);
            fclose(arquivo_temp);
            remove("estoque.txt");
            rename("arquivo_temp.txt", "estoque.txt");
            printf("Lista atualizada com sucesso!");
            break;


        case 3:
            int deletar;
            FILE *arquivo_tempo = fopen("arquivo_temp.txt", "w");
            printf("-Lista de Produtos-\n");           

            while (fgets(linha, sizeof(linha), entrada) != NULL){
                printf("%d. %s",i+1, linha);
                i +=1;
                    }
            printf("Insira a posicao do produto você deseja excluir: ");
            scanf("%d", &deletar);

            num_linha = 1;
            rewind(entrada);
            while (fgets(linha, sizeof(linha), entrada) != NULL){
                if (num_linha != deletar){
                    fputs(linha, arquivo_tempo);
                }
                num_linha++;
            }

            fclose(entrada);
            fclose(arquivo_tempo);
            remove("estoque.txt");
            rename("arquivo_temp.txt", "estoque.txt");
            printf("Lista atualizada com sucesso!");
            break;


        case 4:
            printf("-Lista de Produtos-\n");

            while (fgets(linha, sizeof(linha), entrada) != NULL){
                printf("%d. %s",i+1, linha);
                i +=1;
                    } 
                    break;
               
        case 0:
            sair = 0;
            break;
                }
                
            
        }
    
    }
    return 0;        
}
