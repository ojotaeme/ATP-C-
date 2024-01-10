#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct itens item;
struct itens {
	int info;
	item *next; 	// autorreferenciamento
};

typedef struct lista{
	item *first;
	item *last;
	item *current;
}lista;

// -------------- prototipos ---------------------
lista * cria_lista();
item * cria_item(int num, lista *lista);
void insere_na_lista(item *item, lista *lista);
int compara_listas(lista *lista1, lista *lista2, int igual);

int main(){

	int i=0, j=0;
	int ret, igual = 0;

	int *num1= (int *) malloc (sizeof(int));
	int *num2 = (int *) malloc (sizeof(int));

	item *vet1; // = (item *) malloc (sizeof(item));
	item *vet2; // = (item *) malloc (sizeof(item));

	lista *lista1 = cria_lista();
	lista *lista2 = cria_lista();

	// preenche lista 1
	do{
		//printf("Elemento %d da lista 1: ", i);
		scanf(" %d", &num1[i]);

		if(num1[i] != 0){

			vet1 = cria_item(num1[i], lista1);	// aloca na memoria dinamicamente espaco para o item
			insere_na_lista(vet1, lista1);	// insere na lista o item
		}

		i++;

	}while(num1[i-1] != 0);

	// preenche lista 2
	do{
		//printf("Elemento %d da lista 2: ", j);
		scanf(" %d", &num2[j]);

		if(num2[j] != 0){

			vet2 = cria_item(num2[j], lista2);	// aloca na memoria dinamicamente espaco para o item
			insere_na_lista(vet2, lista2);	// insere na lista o item
		}

		j++;

	}while(num2[j-1] != 0);

	ret = compara_listas(lista1, lista2, igual);
	if(ret == 0){
		printf("N");
	}else{
		printf("S");
	}

	item *aux1;
	item *noh1 = lista1->first;
	while(noh1 != 0){
		aux1 = noh1->next;
		free(noh1);
		noh1 = aux1;
	}

	item *aux2;
	item *noh2 = lista2->first;
	while(noh2 != 0){
		aux2 = noh2->next;
		free(noh2);
		noh2 = aux2;
	}

	free(num1);
	//free(num2);
	free(vet1);
	free(vet2);
	free(lista1);
	free(lista2);
}

// ------------------ funcoes ------------------------

lista * cria_lista(){

	lista *nova_lista = (lista *) malloc (sizeof(lista));		// aloca espaco na memoria dinamica para a struct lista
	assert(nova_lista);		// se der errado encerra o programa

	// declara o primeiro ultimo e atual elemento da lista como null
	nova_lista->first = NULL;
	nova_lista->last = NULL;
	nova_lista->current = NULL;

	return nova_lista;
}

item * cria_item(int num, lista *lista){

	item *novo_item = (item *) malloc (sizeof(item));		// aloca espaco na memoria dinamicamente para a struct item
	assert(novo_item);		// se der errado encerra o programa

	// define o campo info com o num digitado pelo usuario e o campo next com NULL (ultimo elemento)
	novo_item->info = num;
	novo_item->next = NULL;

	return novo_item;
}

void insere_na_lista(item *item, lista *lista){

	if(lista->first == NULL){		// se for verdade eh pq a lista ta vazia entao o ultimo elemento recebe o item
		lista->last = item;
	}

	// define o campo next do item para apontar para o primeiro elemento da lista (q vira o segundo) e os campos primeiro e atual da lista recebem o item
	item->next = lista->first;
	lista->first = item;
	lista->current = item;
}

int compara_listas(lista *lista1, lista *lista2, int igual){

	// condicoes de parada
	if(lista1->first == NULL && lista2->first == NULL){	// caso 1 - as listas sao do mesmo tamanho, elementos podem ser iguais ou nao
		return igual;
	}
	if(lista1->first == NULL || lista2->first == NULL){ // caso 2 - se as listas sao de tamanhos diferentes, necessariamente nao sao iguais, ja retorna zero
		return 0;
	}

	if(lista1->first->info == lista2->first->info){
		igual++;
	}else{
		return 0;
	}

	lista1->first = lista1->first->next;
	lista2->first = lista2->first->next;
	return compara_listas(lista1, lista2, igual);
}

