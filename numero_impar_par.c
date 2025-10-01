#include <stdio.h>

int main(){
	
	int a;
	
	printf("Insira um numero: ");
	scanf("%d", &a);
	
	if (a > 0){
		printf("%d eh um numero positivo", a);
	}
	else if (a == 0){
		printf("%d eh igual a zero", a);
	}
	else{
		printf("%d eh um numero negativo", a);
	}
	
	if (a % 2 == 0 ){
		printf("\n%d eh um numero par", a);
	}
	else if (a == 0){
		printf("\n%d eh neutro", a);
	}
	else{
		printf("\n%d eh impar", a);
	}
}
