#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strcopy(char *dest, char *src);//Prototipo

int strcopy(char *dest, char *src){

    if(*src=='\0'){
        *(dest)=*(src);
        return 0;
    }
    else{
        *(dest)=*(src);
        strcopy(dest+1, src+1);
        return 0;
    }
}

int main(){

    char dest[50];
    char src[50];

    printf("Entrada: ");
    scanf(" %[^\n]%*c", src);

	strcopy(dest, src);

    printf("%s", dest);

    return 0;
}
