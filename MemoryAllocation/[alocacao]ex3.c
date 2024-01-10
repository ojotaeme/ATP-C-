#include<stdio.h>
#include<stdlib.h>

int * elementos_PA(int n, int r, int a1);

int * elementos_PA(int n, int r, int a1){

	int *vetor;
	int i;

	vetor=(int*)malloc(n*sizeof(int));

	for(i=0; i<n; i++){

		vetor[i]=a1;
		a1=a1+r;
	}

	return vetor;
}

int main(){

	int n;
	int r;
	int a1;
	int i;
	int *pa;

	printf("Entrada:\n");
	scanf("%d", &n);
	scanf("%d", &r);
	scanf("%d", &a1);

	pa=elementos_PA(n, r, a1);

	for(i=0; i<n; i++){
		printf("%d ", pa[i]);
	}

	return 0;
}


