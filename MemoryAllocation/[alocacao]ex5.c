#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
	int n;
	int *vetor;
	int *p;

    printf("Entrada: ");
	scanf("%d",&n);
	vetor=malloc(n * sizeof (int));
	p=malloc(n * sizeof (int));

	printf("Valores vetor: ");
        for(i=0; i<n; i++){
            scanf("%d",&vetor[i]);
            p[i]=vetor[i];
        }
    vetor=realloc(vetor,2*n);
        for(i=0; i<2*n; i++){
            if(i<n){
                vetor[i]=p[i];
            }
            else {
                vetor[i]=2*vetor[i-n];
            }
        }
        for(i=0; i<2*n; i++)
        {
            printf("%d ",vetor[i]);
        }
	return 0;
}
