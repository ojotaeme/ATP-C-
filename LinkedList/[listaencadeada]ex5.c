#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef struct itens item;
struct itens {
	int info;
	item *next;
};

typedef struct listadinamica{
	item *first;
	item *last;
	item *current;
}lista;

lista * crialista();
item * criaitem(int num, int condicao);
bool last(lista *lista, item **item);
void inserelista(lista *lista, item *noh);
lista * clonalista(lista *lista1, lista *lista2);
int printalista1(lista *lista1);
int printalista2(lista *lista2);

lista * crialista(){

	lista *novalista=(lista *) malloc(sizeof(lista));
	assert(novalista);
	novalista->first=NULL;
	novalista->last=NULL;
	novalista->current=NULL;

	return novalista;
}

item * criaitem(int num, int condicao){

	item *novoitem=(item *)malloc(sizeof(item));
	assert(novoitem);
	if(condicao==1){

		novoitem->info=2*num;
		novoitem->next=NULL;

	}else{
		novoitem->info=num;
		novoitem->next=NULL;
	}

	return novoitem;
}

bool last(lista *lista, item **aux){

	if (lista->first==NULL){
		return false;
	}
	lista->current=lista->last;
	*aux=lista->current;
	return true;
}

void inserelista(lista *lista, item *noh){

	item *aux;

	if (lista->first==NULL){

		lista->first=noh;
	}else{

		last(lista, &aux);
		aux->next=noh;
	}
	lista->current=noh;
	lista->last=noh;
}

lista * clonalista(lista *lista1, lista *lista2){

	item *vet2=NULL;
	lista2->last=lista1->last;
	lista1->current=lista1->first;
	if(lista1->current==NULL){
		return 0;
	}
	do{
		vet2=criaitem(lista1->current->info, 1);
		inserelista(lista2, vet2);

		lista1->current=lista1->current->next;

	}while(lista1->current!=NULL);

	lista1->current=lista1->first;
	lista2->current=lista2->first;

	return lista2;
}

int printalista1(lista *lista1){

	if(lista1->first==NULL){
		return 0;
	}

	printf("[%d] -> ", lista1->first->info);
	lista1->first = lista1->first->next;

	return printalista1(lista1);
}

int printalista2(lista *lista2){

	if(lista2->first == NULL){
		return 0;
	}

	printf("[%d] -> ", lista2->first->info);
	lista2->first = lista2->first->next;

	return printalista2(lista2);
}

int main(){

	int i=0;
	int ret1;
	int ret2;
	lista *lista2=crialista();
	lista *lista1=crialista();
	int *num=(int *)malloc(sizeof(int));
	item *vet=(item *)malloc(sizeof(item));

	printf("Entrada: ");
	do{
		scanf(" %d", &num[i]);
		if(num[i]!=0){
			vet=criaitem(num[i], 0);
			inserelista(lista1, vet);
		}
		i++;

	}while(num[i-1] != 0);

	lista2=clonalista(lista1, lista2);
	ret1=printalista1(lista1);
	if(!ret1){
		printf("[NULL]\n");
	}
	ret2=printalista2(lista2);
	if(!ret2){
		printf("[NULL]");
	}

	return 0;
}
