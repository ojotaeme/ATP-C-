#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int n;
    struct no *prox;
}no;

typedef struct{
    no *p1;
    no *p2;
    int tam;
}Lista;

void printlista(no *teste);

void printlista(no *teste) {

	printf("[%d] -> ", teste->n);
	teste=teste->prox;
	if(teste->prox==NULL){
		printf("[%d] -> ", teste->n);
		printf("[NULL]");

		return;
	}
   	printlista(teste);
}

int main() {
    Lista lista;
    int valor;
    int i;

    scanf("%d", &lista.tam);

    for(i=0;i<lista.tam;i++){

        scanf("%d", &valor);
        no *n1=(no*)malloc(sizeof(no));
	    n1->n=valor;

	    if(lista.p1==NULL){
        	n1->prox = NULL;
	        lista.p1=n1;
	        lista.p2=n1;
		}else{
			n1->prox=lista.p1;
	        lista.p1=n1;
		}
	}

	no *teste=lista.p1;
    printlista(teste);

    return 0;
}





