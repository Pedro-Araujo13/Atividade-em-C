#include <stdio.h>

int main(){
	
	float peso_excedente, peso_peixe, valor_pago;
	int regulamento;
	
	regulamento = 50;
	 	
		 printf("insira o peso em kg do peixe pescado: \n");
	 		scanf(" %f", &peso_peixe);
		
		peso_excedente = peso_peixe - regulamento;
			
			if (peso_excedente > 0)
			{
				valor_pago = peso_excedente * 4;
				printf("Voce excedeu o peso estabelecido! A multa eh de: ");
				printf("R$ %2.f", valor_pago);
			}
			
			else
			{
				printf("Voce nao excedeu o regulamento!");	
			}
		
		return 0;

}
