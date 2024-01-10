#include<stdio.h>
#include<stdlib.h>

void figurinhas(int *fig,int n);

void figurinhas(int *fig,int n){

    int i;
    int j;
    int aux;

	for(i=n-3; i<n; i++){
		aux=fig[i];
		j=i-1;
		while((j>=0)&&(aux<fig[j])){
			fig[j+1]=fig[j];
			j--;
		}
		fig[j+1]=aux;
	}
	return;
}

int main()
{
    int i;
    int *fig;
    int n2;

	scanf("%d",&n2);
	fig=(int *)malloc(sizeof(int)*n2);
	for(i=0;i<n2;i++){
		scanf("%d",&fig[i]);
	}
	figurinhas(fig,n2);
	for(i=0; i<n2; i++){
		printf("%d ",fig[i]);
	}
	return 0;
}

