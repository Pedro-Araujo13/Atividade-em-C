#include <stdio.h>
#include <stdlib.h>

int candidato1 = 0, candidato2 = 0, candidato3 = 0;

void votar(){
    int canditato;
    printf("Deseja votar em qual candidato? (1, 2 ou 3): ");
    scanf("%d", &canditato);

    switch(canditato){
        case 1:
            candidato1++;
            printf("Voto registrado com sucesso!\n");
            break;
        case 2:
            candidato2++;
            printf("Voto registrado com sucesso!\n");
            break;
        case 3:
            candidato3++;
            printf("Voto registrado com sucesso!\n");
            break;
        default:
            printf("Opcao inválida");
            break;
    }
}
void resultados(){
    printf("\nResultado da eleição:\n");
    printf("Candidato 1: %d votos\n", candidato1);
    printf("Candidato 2: %d votos\n", candidato2);
    printf("Candidato 3: %d votos\n", candidato3);
}

void salvar_resultados(){
      FILE *file = fopen("resultado.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar arquivo!\n");
        return;
    }
    fprintf(file, "Resultado da eleição:\n");
    fprintf(file, "Candidato 1: %d votos\n", candidato1);
    fprintf(file, "Candidato 2: %d votos\n", candidato2);
    fprintf(file, "Candidato 3: %d votos\n", candidato3);
    fclose(file);
    printf("Resultado salvo em 'resultado.txt' com sucesso!\n");
}

int main(){

    int opcao;

    do{
    printf("1.) Votar \n2.) Resultados \n3.) Encerrar \nEscolha uma opcao:");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            votar();
            break;
        case 2:
            resultados();
            break;
        case 3:
            salvar_resultados();
            printf("Encerrando Sistema...\n");
            break;
        default:
            printf("Opcao inválida!\n");
    }
        }while(opcao != 3);


    
}