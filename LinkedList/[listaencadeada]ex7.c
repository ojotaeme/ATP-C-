#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef struct itens item;
struct itens {
	int info;
	item *next;
};

typedef struct lista {
	item *first;
	item *last;
	item *current;
} lista;

lista * crialista();
item * criaitem(int num, lista *lista);
bool last(lista *lista, item **item);
void inserelista(lista *lista, item *noh);
int compara(lista *lista, int cont);

lista * crialista(){

	lista *novalista=(lista *)malloc(sizeof(lista));
	assert(novalista);
	novalista->first = NULL;
	novalista->last = NULL;
	novalista->current = NULL;

	return novalista;
}

item * criaitem(int num, lista *lista){

	item *novoitem=(item *)malloc(sizeof(item));
	assert(novoitem);
	novoitem->info = num;
	novoitem->next = NULL;

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
	}
	else{
		last(lista, &aux);
		aux->next=noh;
	}
	lista->current=noh;
	lista->last=noh;
}

int compara(lista *lista, int cont){

	if(lista->first==NULL){
		return 0;
	}
	if(lista->first->info==cont){
		return cont;
	}
	cont++;
	lista->first=lista->first->next;
	return compara(lista, cont);

}

int main(){

	int N;
	int i;
	int ret;
	int cont=1;
	lista *lista = crialista();
	int *num = (int *) malloc (sizeof(int));
	item *vet = (item *) malloc (sizeof(item));

	printf("Entrada: ");
	scanf(" %d", &N);
	for(i=0; i<N; i++){
		scanf(" %d", &num[i]);
		vet=criaitem(num[i], lista);
		inserelista(lista, vet);
	}
	ret=compara(lista, cont);
	printf("%d", ret);

	return 0;
}
