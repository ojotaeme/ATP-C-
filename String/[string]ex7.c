#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pUpm pfpiplpmpe plpepgpapl

int main() {

    int n = 0;
    int i;
    char str[50];
    fgets(str, 50, stdin);

    for (i=0; i<strlen(str); i++){

    if (str[i]=='\n' || str[i]=='\0') {
        printf("\n");
        };
    if (n){
        printf("%c", str[i]);
        n=0;
        }
    if (str[i]==' '){
        printf(" ");
        }
    if (str[i]=='p'){
        n=1;
        }
    }
        return 0;
}
