#include<stdio.h>
#include<stdlib.h>

int contabolas(int *bolas);

int contabolas(int *bolas){
    int i;
    int j;
    int cont;

	for(i=0;i<8;i++){
        cont=0;
		for(j=0;j<8;j++){
			if(bolas[j]==bolas[i]){
				cont++;
				if(cont>4){
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
    int i;
    int *bolas;
    int n;
	bolas=(int *)malloc(sizeof(int)*8);

	for(i=0;i<8;i++){
		scanf("%d",&bolas[i]);
	}
	n=contabolas(bolas);
	if(n==0){
		printf("S");
	}else{
		printf("N");
	}
}


