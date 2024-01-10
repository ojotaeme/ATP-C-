#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countwords(char *str);//Prototipo

int countwords(char *str){
    int n=1;
    int i=0;

    for(i=0;i<=50;i++){
        if(str[i]==' '){
            n++;
        }
    }
    return n;
}

int main(){

    char stri[50];

    printf("Entrada: ");
    scanf("%[^\n]%*c",stri);

    printf("%d",countwords(stri));

    return 0;
}
