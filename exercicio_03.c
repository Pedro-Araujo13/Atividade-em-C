#include <stdio.h>

int main(){
	
	float saldo, saque, deposito, transferencia, saldo_atual;
	int opcao, pix;
	saldo = 1000;
	printf(" ----------NUBANCO---------- \n");
	printf(" --- Selecione a opcao desejada --- \n\n");
	printf("1 - Saldo \n");
	printf("2 - Saque \n");
	printf("3 - Deposito \n");
	printf("4 - Transferencia \n");
	printf("5 - Sair \n");
		scanf("%d", &opcao);
		
	switch (opcao)
	{
		case 1:
			printf(" --- SALDO --- \n\n");
			printf("R$%.2f\n", saldo);
			break;
			
		case 2:
			printf(" --- SAQUE --- \n\n");
			printf("Insira o valor que deseja sacar: ");
				scanf("%f", &saque);
			if (saque > saldo)
			{
				printf("Valor de saque indisponivel");
			}
			else
			{		
			saldo_atual = saldo - saque;
			printf("Saque realizado com sucesso!\n");
			printf("--- Saldo atual: R$ %.2f ---", saldo_atual);
			}
			break;
			
		case 3:
			printf(" --- DEPOSITO --- \n\n");
			printf("Insira o valor que deseja depositar: ");
				scanf("%f", &deposito);
			saldo_atual = deposito + saldo;
			printf("Deposito realizado com sucesso!\n");
			printf(" --- Saldo atual: R$ %.2f --- \n", saldo_atual);
			break;
			
		case 4:
			printf(" --- AREA DE TRANSFERENCIA --- \n\n");
			printf("Insira a chave pix: \n");
				scanf("%d", &pix);
			printf("Insira o valor a ser transferido: \n");
				scanf("%f", &transferencia);
			if (transferencia > saldo)
			{
				printf("Valor indisponivel na conta");
			}
			else
			{		
			saldo_atual = saldo - transferencia;
			printf("Transferencia realizada com sucesso!\n");
			printf("--- Saldo atual: R$ %.2f ---", saldo_atual);
			}
			break;
			
		case 5:
			break;
		default:
			printf("opcao invalida!");	
			
			
	}

	return 0;
}
