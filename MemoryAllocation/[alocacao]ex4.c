#include<stdio.h>
#include<stdlib.h>

typedef struct time{
	int horas;
	int minutos;
	int segundos;
} Time;

Time * time_conversor(int n);

Time * time_conversor(int n){

	Time *tempo;
	int hora=n%3600;
	int minuto;

	hora=n%3600;
	tempo=(Time*)malloc(sizeof(Time));

	tempo->horas=n/3600;
	tempo->minutos=hora/60;

	minuto=hora%60;
	tempo->segundos=minuto;

	return tempo;
}

int main(){

	Time *tempo;
	int n;

	printf("Entrada: ");
	scanf("%d", &n);

	tempo=time_conversor(n);

	printf("H: %d\nM: %d\nS: %d", tempo->horas, tempo->minutos, tempo->segundos);
}

