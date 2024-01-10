#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarVogais(char *str);

int contarVogais(char *str){

    int n=0;
    int i;

    for(i=0; str[i]!='\0';i++){
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
            n=n+1;
        }
        else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
            n=n+1;
        }
    }

    return n;
}

int main()
{

    char str[50];

    printf("Entrada: ");
    scanf("%[^\n]%*c",str);
	printf("%d",contarVogais(str));

	return 0;

}
