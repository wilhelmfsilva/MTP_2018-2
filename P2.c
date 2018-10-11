#include <stdio.h>

double exp (int numero, int expoente)
{
	int i;
	double resultado = 1;

	for (i=0; i<expoente; i++)
		resultado = resultado * numero;
	return resultado;
}

void inverter (char vet[])
{
	int aux = 0, i, cont = 0, contagem = 0;
	for (i=0; vet[i] != '\0'; i++)
		cont++;
	contagem = cont;
	cont--;
	for (i=0; i<cont; i++)
	{
		aux = vet[i];
		vet[i] = vet[cont];
		vet[cont] = aux;
		cont--;
	}
	vet[contagem] = '\0';
}

int BintoDec (char num[])
{
	inverter(num);
	int i;
	double soma = 0;
	for (i = 0; num[i] != '\0'; i++)
		if (num[i] == '1')
			soma = soma + num[i] * exp(2, i);
	return soma/49;
}

void TruuDectoBin(int numero){
    int i, nb, bin[1000];

    for(nb=0; numero>= (1<<nb); nb++);

    for (i = nb; i >= 0; i--)
   {
      if (numero % 2 == 0)
         bin[i] = 0;
      else
         bin[i] = 1;
      numero = numero / 2;
   }

    for (i=1;i<nb+1;i++)
       printf("%d", bin[i]);
}

void DectoBin (int num)
{
	int vet[256], i, j, res, flag=0;
	res = num;
	for (i=0; flag<1 ; i++)
	{
		vet[i] = res % 2;
		res = res/2;
		if (res == 1 || res == 0)
		{
			vet[i+1] = res;
			j=i+1;
			flag++;
		}
	}
	for (i=j; i>=0; i--)
		printf ("%d", vet[i]);
}

int main()
{
	int indice, i;
	char bits[256];

	scanf ("%d", &indice);

	if(indice==1)
	{
		scanf ("%s", bits);
		printf ("\n%d", BintoDec(bits));
	}
	if(indice==2)
	{
		scanf ("%s", bits);
		printf ("\n%x", BintoDec(bits));
	}
	if(indice==3)
	{
		int(bits);
		scanf ("%x", &bits);
		printf ("\n%d", bits);
	}
	if(indice==4)
	{
		int(bits);
		scanf ("%x", &bits);
		DectoBin(bits);
	}
	if(indice==5)
	{
		int(num);
		scanf("%d", &num);
		TruuDectoBin(num);
	}
	if(indice==6)
	{
		int(bits);
		scanf("%d", &bits);
		printf ("\n%x", bits);
	}
	if(indice==7)
	{
		int(bits);
		scanf("%o", &bits);
		printf("\n%d", bits);
	}
	if(indice==8)
	{
		int(bits);
		scanf("%d", &bits);
		printf ("\n%o", bits);
	}
	return 0;
}

