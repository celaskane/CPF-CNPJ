#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int conversao(char entrada[], int cpf[])
{	int i, j, tamanho = strlen(entrada);
	for(i=0, j=0; i<tamanho; i++){
		if(entrada[i] >= '0' && entrada[i] <= '9'){
			if(j<11) cpf[j] = entrada[i] - '0';
			j++;
		}
	}
	return j;
}

bool verificaDigito(int cpf[], int mult[], int N)
{	int i, soma = 0;
	for(i=0; i<N; i++){
		soma = soma + cpf[i]*mult[i];
	}
	int resto = ((soma*10) % 11)%10;
	return resto == cpf[N];
}

bool todosRepetidos(int cpf[])
{	int i;
    for(i=1; i<11; i++){
        if(cpf[i] != cpf[0]) return false;
    }
    return true;
}

void imprimeEstado(int cpf[])
{
	switch(cpf[8]){
		case 0: printf("Rio Grande do Sul"); break;
		case 1: printf("Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins"); break;
		case 2: printf("Amazonas, Pará, Roraima, Amapá, Acre e Rondônia"); break;
		case 3: printf("Ceará, Maranhão e Piauí"); break;
		case 4: printf("Paraíba, Pernambuco, Alagoas e Rio Grande do Norte"); break;
		case 5: printf("Bahia e Sergipe"); break;
		case 6: printf("Minas Gerais"); break;
		case 7: printf("Rio de Janeiro e Espírito Santo"); break;
		case 8: printf("São Paulo"); break;
		case 9: printf("Paraná e Santa Catarina");
	}
}

int main()
{
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	char entrada[50];
	printf("Entre com os 11 digitos do CPF:");
	fgets(entrada, 50, stdin);
	conversao(entrada, cpf);
	
	if(verificaDigito(cpf, m1, 9) && verificaDigito(cpf, m2, 10) && !todosRepetidos(cpf)){
		printf("\nCPF valido, vindo do(s) Estado(s) de ");
		imprimeEstado(cpf);
	}
	else{
		printf("\nErro no cpf.");
	}

	return 0;
}
