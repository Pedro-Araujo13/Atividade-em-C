
#include <stdio.h>

int main(){
	
	float velocidade, velocidade_max, multa, percentual_1, percentual_2;
	
	printf("insira a velocidade de um veículo: \n");
		scanf("%f", &velocidade);
	printf("Insira a velocidade maxima permitida: \n");
		scanf("%f", &velocidade_max);
		
		if (velocidade > velocidade_max)
		{	
			percentual_1 = velocidade_max *1.1;
			percentual_2 = velocidade_max *1.2;
			if (velocidade == percentual_1)
			{
				printf("Voce estava 10%% alem do limite estabelecido!\nA multa eh de R$ 50.00");
			}
			else if (velocidade > percentual_1 && velocidade <= percentual_2)
			{
				printf("Voce estava entr 11%% e 20%% alem do limite de velocidade estabelecido!\nA multa eh de R$ 100.00");
			}
			else if (velocidade > percentual_2)
			{
				printf("Voce excedeu a velocidade limite em mais de 20%%!! \nA multa sera de R$ 200.00");
			}
		}
		                                                                    
		else
		{
			printf("Parabens! voce estava dentro do limite de velocidade!");
		}
		return 0;
}

