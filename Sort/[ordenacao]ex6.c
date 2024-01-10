#include<stdio.h>
#include<stdlib.h>

int main(){

	int q;
	int i;
	int j;
	int menor;
	int n;
	int cont=0;
	int *vetor=(int *)malloc(sizeof(int));

	scanf("%d", &q);
	for(i=0; i<q; i++){
		scanf("%d", &vetor[i]);
	}
	for(i=0; i<(q-1); i++){

		menor=i;

		for(j=(i+1); j<q; j++){
			if(vetor[j]<vetor[menor]){
				menor=j;
			}
		}
		if(vetor[menor]<50){
			n=vetor[menor];
			vetor[menor]=vetor[i];
			vetor[i]=n;
			cont++;
		}
		else{
			break;
		}
	}
	for(i=0; i<cont; i++){
		printf("%d ", vetor[i]);
	}

	return 0;
}
