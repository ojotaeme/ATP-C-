#include <stdio.h>
#include <stdlib.h>

char * charToString(char c);

char * charToString(char c){

    char *str;

    str=(char*)malloc(sizeof(char));
    *str=c;
    *(str+1)='\0';

    return str;
}

int main(){

    char c;
    char *str;

    printf("Entrada: ");
    scanf("%c",&c);
    str=charToString(c);
    printf("%s",str);

    return 0;
}

