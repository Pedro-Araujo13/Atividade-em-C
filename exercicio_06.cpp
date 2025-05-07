
 #include <stdio.h>
 
 int main(){
 	int opcao, diaria, preco_diaria;
 	float preco_final;
 	
 	printf(" ##### HOTEL MACARENA #####\n ");
 	printf(" - Selecione o tipo de de Quarto desejado - \n\n");
 	printf("( 1 ) - Quarto Simples - R$ 150,00 por diaria\n");
 	printf("( 2 ) - Quarto Duplo - R$ 250,00 por diaria\n");
 	printf("( 3 ) - Suite - R$ 400,00 por diaria\n");
 		scanf(" %d", &opcao);
 		
 		switch (opcao)
		 {
 			case 1:
			 printf(" ##### QUARTO SIMPLES #####\n\n");
			 printf("Insira o valor de diarias desejadas: ");
			 	scanf(" %d", &diaria);
				preco_final = diaria * 150;
				printf("O valor total da hospedagem com o quarto escolhido eh de R$ %.2f", preco_final);
				break;
			
			case 2:
			 printf(" ##### QUARTO DUPLO #####\n\n");
			 printf("Insira o valor de diarias desejadas: ");
			 	scanf(" %d", &diaria);
				preco_final = diaria * 250;
				printf("O valor total da hospedagem com o quarto escolhido eh de R$ %.2f", preco_final);
				break;
				
			case 3:
			 printf(" ##### SUITE #####\n\n");
			 printf("Insira o valor de diarias desejadas: ");
			 	scanf(" %d", &diaria);
				preco_final = diaria * 400;
				printf("O valor total da hospedagem com o quarto escolhido eh de R$ %.2f", preco_final);
				break;
			
			default:
				printf("Opcao Invalida!");
		 }
		 return 0;
 }
