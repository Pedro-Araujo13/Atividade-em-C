#include <stdio.h>
#include <stdlib.h>

void cadastrar(){
     printf("Escreva o produto que voce deseja inserir: ");
            scanf("%s", produto);
            fprintf(entrada, "%s\n", produto);
            fclose(entrada);
            printf("Produto cadastrado com sucesso!");
}