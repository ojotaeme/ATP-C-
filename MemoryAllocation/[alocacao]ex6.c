#include <stdio.h>
#include <stdlib.h>

int * matriz_identidade(int n);

int * matriz_identidade(int n){
  int i;
  int j;
  int *matriz=malloc(n*n*sizeof(int));

  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      if (i==j)
        matriz[(i*n)+j]=1;
      else
        matriz[(i*n)+j]=0;
    }
  }
  return matriz;
}

int main()
{
  int n;
  int i;
  int j;
  int *matriz;

  printf("Entrada:");
  scanf("%d", &n);

  matriz=matriz_identidade(n);

  for(i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("%d ", matriz[(i*n)+j]);
        if ((j+1)==n)
        printf("\n");
    }
  }

}


