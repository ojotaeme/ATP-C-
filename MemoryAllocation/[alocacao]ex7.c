#include <stdlib.h>
#include <stdio.h>

char * strcalloc(int l, char c);

char * strcalloc(int l, char c){

    char *str;
    char i;

    str=calloc(l+1,sizeof(char));
    for(i=0; i<l ;i++){
        *(str+i)=c;
        }
        *(str+l)='\0';

    return str;
}

int main(){

    int l;
    int i;
    char *str;
    char c;

    printf("Entrada: ");
    scanf("%d",&l);
    scanf("%c",&c);
    str = strcalloc(l,c);
    printf("%s" ,str);

    return 0;
}

