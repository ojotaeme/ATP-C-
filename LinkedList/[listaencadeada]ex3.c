#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

typedef struct itens item;
struct itens{
	int info;
	item *next;
};

typedef struct lista{
	item *first;
	item *last;
	item *current;
}lista;

lista * crialista();
item * criaitem(int num, lista *lista);
void inserelista(item *item, lista *lista);
int busca(lista *lista, int num, int res);

lista * crialista(){

	lista *novalista=(lista *)malloc(sizeof(lista));
	assert(novalista);
	novalista->first = NULL;
	novalista->last = NULL;
	novalista->current = NULL;

	return novalista;
}

item *criaitem(int num, lista *lista){

	item *novoitem=(item *)malloc(sizeof(item));
	assert(novoitem);
	novoitem->info = num;
	novoitem->next = NULL;

	return novoitem;
}

void inserelista(item *item, lista *lista){

	if(lista->first==NULL){
		lista->last=item;
	}
	item->next=lista->first;
	lista->first=item;
	lista->current=item;
}

int busca(lista *lista, int num, int res){

	if(lista->first==NULL){
		return res;
	}

	if(lista->first->info==num){
		res++;
	}

	lista->first = lista->first->next;
	return busca(lista, num, res);
}

int main(){

	int n;
	int b;
	int i;
	int ret;
	int res=0;
	int *num=(int *)malloc(sizeof(int));
	item *vet=(item *)malloc(sizeof(item));
	lista *lista=crialista();

	printf("Entrada: ");
	scanf("%d %d", &n, &b);

	for(i=0; i<n; i++){

		scanf(" %d", &num[i]);
		vet = criaitem(num[i], lista);
		inserelista(vet, lista);
	}

	ret = busca(lista, b, res);
	if(ret == 0){
		printf("N");
    }
	else{
		printf("S");
	}

    return 0;
}
