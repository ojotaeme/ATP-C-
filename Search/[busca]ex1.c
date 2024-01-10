#include<stdio.h>
#include<stdlib.h>

int main(){

	int p;
	int n;
	int i;
	int *vetor=0;
	int heroi=0;
	int monstro=0;

	scanf(" %d", &p);
	scanf(" %d", &n);
	vetor=(int *)malloc(n*sizeof(int));
	for(i=0; i<n; i++){
		scanf(" %d", &vetor[i]);
	}
	for(i=0; i<n; i++){
		if(vetor[i]<=p ){
			heroi++;
			monstro=monstro+vetor[i];
		}
	}
	printf("%d %d", heroi, monstro);
	return 0;
}
