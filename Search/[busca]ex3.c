#include <stdio.h>
#include <stdlib.h>

void inserir (int *vetor, int tam)
{
	int i;
	for (i=0;i<tam;i++)
	{
		scanf ("%d", &vetor[i]);
	}
}

int busca (int n, int *vetor1, int tam )
{
	int i;
	for (i=0;i<tam;i++)
	{
		if (n==vetor1[i])
		{
			return -1;
		}
	}
	return n;
}
int main ()
{
	int tam1;
	int tam2;
	int *vetor1;
	int *vetor2;
	int *vetor3;
	int resp;
	int cont=0;
	int i;

	scanf ("%d %d", &tam1, &tam2);
	vetor1=malloc(tam1*sizeof(int));
	vetor2=malloc(tam2*sizeof(int));
	vetor3=malloc(tam1*sizeof(int));
	inserir(vetor1,tam1);
	inserir(vetor2,tam2);

	for (i=0;i<tam1;i++)
		vetor3[i]=vetor1[i];

	for (i=0;i<tam2;i++)
	{
		resp=busca(vetor2[i],vetor1,tam1);
		if (resp!=-1)
		{
			cont++;
			vetor3=realloc(vetor3, tam1 + cont);
			vetor3[tam1+cont-1]=resp;
		}
	}
	for (i=0;i<tam1+cont;i++)
	{
		printf ("%d ", vetor3[i]);
	}
    return 0;
}
