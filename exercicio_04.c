
#include <stdio.h>
#include <stdbool.h>

int main(){
	
	int num, primo, i;
	bool a;
		printf("Insira um numero para verificar se eh primo: \n");
			scanf(" %d", &num);
		if (num == 0)
		{
			printf("O numero 0 nao eh primo;");	
		}
		else if (num == 1)
		{
			printf("O numero 1 nao eh primo");
		}
		else
		{
		a = false;
		for (i = 2; i < num; i++)
		{
			primo = num % i;
			if (primo == 0)
			{
				a = true;
			}	
		}
		if (a == true)
		{
			printf("O numero escolhido nao eh primo");
		}
		else
		{
			printf("O numero escolhido eh primo");	
		}
		}
	return 0;
	
}
