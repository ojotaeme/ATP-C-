#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef struct itens item;
struct itens {
	int info;
	item *next;
};

typedef struct lista{
	item *first;
	item *last;
	item *current;
} lista;

lista * crialista();
item * criaitem(int num, lista *lista);
bool last(lista *lista, item **item);
void inserelista(lista *lista, item *noh);
int veordem(lista *lista);

lista * crialista(){

	lista *novalista=(lista *)malloc(sizeof(lista));
	assert(novalista);

	return novalista;
}

item * criaitem(int num, lista *lista){

	item *novoitem=(item *)malloc(sizeof(item));
	assert(novoitem);

	novoitem->info=num;
	novoitem->next=NULL;

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
		aux->next = noh;
    }
	lista->current = noh;
	lista->last = noh;
}

int veordem(lista *lista){

	int aux;

	if(lista->first->next == NULL){
		return 1;
	}

	aux=lista->first->info;
	lista->first=lista->first->next;

	if(aux<=lista->first->info){
		return veordem(lista);
	}else{
		return 0;
	}

}


int main(){

	int i;
	int ret;
	lista *lista=crialista();
	int *num=(int *)malloc(sizeof(int));
	item *vet=(item *)malloc(sizeof(item));

	do{
		scanf(" %d", &num[i]);

		if(num[i]!=0){
			vet=criaitem(num[i], lista);
			inserelista(lista, vet);
		}
		i++;
	}while(num[i-1]!=0);

	ret=veordem(lista);
	if(ret==0){
		printf("N");
	}else{
		printf("S");
	}
    return 0;
}

