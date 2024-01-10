#include <stdio.h>
#include <stdlib.h>

int strlength(char *str);//Prototipo
int resp=0;

int strlength(char *str){
    if(*str=='\0'){
        return 0;
    }
    else{
        strlength(str+1);
        resp++;
        return resp;
    }
}

int main(){
    int n;
    char *str;
    str=(char*)malloc(31*sizeof(char));

    printf("Entrada: ");
    scanf(" %[^\n]%*c", str);//Receber as cadeias de caracteres
    n=strlength(str);

    printf("%d", n);

    return 0;
}
