#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char str1[50], str2[50];
    fp = fopen("teste.txt", "w");
    if (fp == NULL)
    {
        printf("Erro");
        getchar();
        return 0;
    }
    scanf(" %[^\n]%*c", str1);
    fputs(str1,fp);
    fflush(stdin);
    fclose(fp);
    fp = fopen("teste.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", str2);
        printf("%s ", str2);
    }
    getchar();
    return 0;
}
