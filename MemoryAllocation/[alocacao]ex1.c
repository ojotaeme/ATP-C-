#include<stdio.h>
#include<stdlib.h>

int *nextPrime(int n);s

int * nextPrime(int n){

	int i;
	int j;
	int k;
	int *prime;

	for(i=(n+1); i<=10000; i++){
		k=0;
		for(j=1; j<=i; j++){
			if(i%j==0){
                k++;
			}
		}
            if(k==2){
                prime=(int*) malloc(sizeof(int));
			if(prime==NULL){
				printf("Erro");
			}else{
				*prime=i;
				return prime;
			}
		}
	}
	return 0;
}

int main(){

	int n;
	int *prime;

	printf("Entrada: ");
	scanf("%d", &n);

	if(n<=2 || n>=10000){
        printf("Numero invalido");
	}
    else{
        prime=nextPrime(n);
        printf("%d", *prime);
        free(prime);
    }

}
