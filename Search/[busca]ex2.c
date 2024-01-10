#include<stdio.h>
#include<stdlib.h>

int main(){

	int r;
	int n;
	int i;
	int *vetor=0;
	int pa=1;

	scanf(" %d", &r);
	scanf(" %d", &n);
	vetor=(int *)malloc(n * sizeof(int));

	for(i=0; i<n; i++){
		scanf(" %d", &vetor[i]);
	}
	for(i=0; i<n; i++){
		if(vetor[i]!=pa){
			printf("%d", pa);
			break;
		}
		pa=pa+r;
	}
	return 0;
}
