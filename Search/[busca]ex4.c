#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busca (char *sopa, char str,int tam)
{
	int i;
	for (i=0;i<tam;i++)
		if (sopa[i]==str)
		{
			sopa[i]=' ';
			return 1;
		}
	return 0;
}

int main ()
{
	char *sopa;
	char str[100];
	int i;
	int tam;
	int tam2;
	int cont=0;

	scanf("%d", &tam);

	sopa=malloc(tam*sizeof(char));

	for(i=0;i<tam;i++){
        scanf(" %c", &sopa[i]);
	}

	scanf("%s", str);
	tam2=strlen(str);

	for(i=0;i<tam2;i++){
        cont+=busca(sopa,str[i],tam);
        if(cont==tam2){
            printf ("S");
        }
        else{
            printf ("N");
        }
	}
        return 0;
}
