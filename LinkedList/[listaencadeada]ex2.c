#include<stdio.h>
#include<stdlib.h>
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
int printalista(lista *lista);
int conta(int cont, lista *lista);

lista * crialista(){

	lista *novalista = (lista *)malloc(sizeof(lista));
	assert(novalista);
	novalista->first=NULL;
	novalista->last=NULL;
	novalista->current=NULL;

	return novalista;
}

item * criaitem(int num, lista *lista){

	item *novoitem=(item *)malloc(sizeof(item));
	assert(novoitem);
	novoitem->info=num;
	novoitem->next=NULL;

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

int conta(int cont, lista *lista){

	if(lista->first==NULL){
		return cont;
	}
	cont++;
	lista->first=lista->first->next;

	return conta(cont, lista);
}

int main(){
	int i=0;
	int cont=0;
	int ret;
	int *num;
	item *vet;
	lista *lista;

	num=(int *)malloc(sizeof(int));
	vet=(item *)malloc(sizeof(item));

	lista=crialista();
	do{
		scanf(" %d", &num[i]);
		if(num[i]!=0){
			vet=criaitem(num[i], lista);
			inserelista(vet, lista);
		}
		i++;
	}while(num[i-1]!=0);

	ret = conta(cont, lista);
	printf("%d", ret);

	return 0;
}

