#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcao;
    char produto[50];
    char arquivo[50] = "estoque.txt";

    printf("Menu: \n1. Cadastrar Produto \n2. Editar Produto \n3. Deletar Produto \n4. Listar Produto \n0. Sair \nEscolha uma opcao: ");
    scanf("%d", &opcao);

    if (opcao < 0 || opcao > 4) {
        printf("Opcao Invalida!\n");
        return 1;
    } else {
        switch (opcao) {
            case 1:
                printf("Escreva o produto que voce deseja inserir: ");
                scanf("%s", produto);

                FILE *entrada = fopen(arquivo, "a");
                if (entrada == NULL) {
                    printf("Erro ao abrir o arquivo!\n");
                    return 1;
                } else {
                    fprintf(entrada, "%s\n", produto);
                    fclose(entrada);
                    printf("Produto cadastrado com sucesso!\n");
                }
                break;

            default:
                printf("Opcao ainda nao implementada!\n");
        }
    }
    return 0;
}
