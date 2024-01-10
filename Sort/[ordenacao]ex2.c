#include<stdio.h>
#include<stdlib.h>

int main(){

	int tam=5;
	int i;
	int j;
	int aux;
	int d=0;
	int t;
	int *vetor=(int *)malloc(sizeof(int));

	for(i=0; i<tam; i++){

		scanf(" %d", &vetor[i]);
	}
	for(i=0; i<(tam-1); i++){
		t=0;
		for(j=1; j<(tam); j++){
			if(vetor[j]<vetor[j-1]){
				aux=vetor[j];
				vetor[j]=vetor[j-1];
				vetor[j-1]=aux;
				t++;
			}
		}
		if(t!=0){
			d++;
		}
	}
	if(d==0){
		printf("C");
	}else if(d==(tam-1)){
		printf("D");
	}else{
		printf("N");
	}

	return 0;
}
