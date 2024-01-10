#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leetConverter(char *str);
int i=0;

void leetConverter(char *str){

	switch(str[i]){
		case '4':
			printf("A");
			break;
		case '8':
			printf("B");
			break;
		case 'c':
			printf("C");
			break;
		case 'd':
			printf("D");
			break;
		case '3':
			printf("E");
			break;
		case 'f':
			printf("F");
			break;
		case '9':
			printf("G");
			break;
		case '#':
			printf("H");
			break;
		case '1':
			printf("I");
			break;
		case 'j':
			printf("J");
			break;
		case 'k':
			printf("K");
			break;
		case '/':
			printf("L");
			break;
		case 'm':
			printf("M");
			break;
		case 'n':
			printf("N");
			break;
		case '0':
			printf("O");
			break;
		case '?':
			printf("P");
			break;
		case 'q':
			printf("Q");
			break;
		case 'r':
			printf("R");
			break;
		case '5':
			printf("S");
			break;
		case '7':
			printf("T");
			break;
		case 'u':
			printf("U");
			break;
		case 'v':
			printf("V");
			break;
		case 'w':
			printf("W");
			break;
		case 'x':
			printf("X");
			break;
		case '2':
			printf("Y");
			break;
		case 'z':
			printf("Z");
			break;
		case ' ':
			printf(" ");
			break;
		case '\0':
			return 0;
	}
	i = i+1;
	leetConverter(str);
	return 0;

}

int main(){
	char str[50];
	scanf(" %[^\n]%*c", str);

	leetConverter(str);

}

