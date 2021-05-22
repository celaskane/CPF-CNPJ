#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int conversao(char entrada[], int cnpj[])
{	int i, j, tamanho = strlen(entrada);
	for(i=0, j=0; i<tamanho; i++){
		if(entrada[i] >= '0' && entrada[i] <= '9'){
			if(j<15) cnpj[j] = entrada[i] - '0';
			j++;
		}
	}
	return j;
}

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
	int qtdeDigitos;
	char entrada[50];
	printf("Entre com os 14 digitos do CNPJ:");
	fgets(entrada, 50, stdin);
	qtdeDigitos = conversao(entrada, cnpj);
	
	if(verificaDigito(cnpj, m1, 12) && verificaDigito(cnpj, m2, 13) && qtdeDigitos < 15){
		printf("\nCNPJ valido.", cnpj);
	}
	else{
		printf("\nErro no CNPJ.");
	}

	return 0;
}
