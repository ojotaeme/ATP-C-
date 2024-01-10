#include<stdio.h>
#include<stdlib.h>

int vice(int *p,int n);

int main(void)
{
    int i;
    int n;
    int *p;
	scanf("%d",&n);
	p=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}

	printf("%d",vice(p,n));
	return 0;
}

int vice(int *p,int n){

    int i;
    int j;
    int k;

	for(i=0;i<=1;i++){
		for(j=1;j<n-i;j++){
			if(p[j]>p[j-1]){
				k=p[j];
				p[j]=p[j-1];
				p[j-1]=k;
			}
		}
	}
	return p[1];
}
