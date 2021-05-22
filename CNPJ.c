#include<stdio.h>
#include<stdbool.h>
bool verificaDigito(int cnpj[], int mult[], int N)
{	int i, soma = 0;
	for(i=0; i<N; i++){
		soma = soma + cnpj[i]*mult[i];
	}
	int resto = ((soma*10) % 11)%10;
	return resto == cnpj[N];
}

int main()
{
	int cnpj[14];
	int m1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int m2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	int i;
	printf("Entre com os 11 digitos do CNPJ:");
	for(i=0;i<14;i++)
	{	scanf("%d", &cnpj[i]);
	}
	
	if(verificaDigito(cnpj, m1, 12) && verificaDigito(cnpj, m2, 13)){
		printf("\nCNPJ valido.");
	}
	else{
		printf("\nErro no CNPJ.");
	}

	return 0;
}

