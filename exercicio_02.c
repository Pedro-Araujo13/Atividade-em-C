#include <stdio.h>
#include <math.h>

int main(){
	
	float metros_quadrados, preco, litros, quantidade_tintas;
	
		printf("Insira quantos metros quadrados voce deseja pintar: \n");
			scanf("%f", &metros_quadrados);
		
		litros = metros_quadrados / 3;
		printf("Sera(ao) necessarios %.0f litro(s)", litros);	
		printf(" para pintar a area desejada.\n");
		
		quantidade_tintas = ceil(litros / 18);

		
		preco = quantidade_tintas * 80;
		
		printf("A quantidade total de tinta(s) necessaria(s) sera de %.0f lata \nE o valor final fica por de R$ %.2f", quantidade_tintas, preco);
		
		return 0;
		
	
}
