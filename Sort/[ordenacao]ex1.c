#include<stdio.h>
#include<stdlib.h>

void ordenacrianca(int *fila,int n);

void ordenacrianca(int *fila,int n){
    int i;
    int j;
    int cont=0;
    int aux;
    int menor;
    int temp;

	for(i=0;i<n;i++){
		aux=0;
		menor=i;
    for(j=i+1;j<n;j++){
        if(fila[j]<fila[menor]){
            menor=j;
            aux++;
			}
		}
		temp=fila[menor];
		fila[menor]=fila[i];
		fila[i]=temp;
		if(aux>0){
			cont++;
		}
	}
	printf("%d",cont);
}

int main()
{
    int i;
    int n;
    int *fila;
	scanf("%d",&n);
	fila=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&fila[i]);
	}
	ordenacrianca(fila,n);
}
