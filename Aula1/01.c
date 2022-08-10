#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* StrCat (char *destino, char *origem);
int StrLen (char *string);
int StrCmp(char *string1, char *string2);

int main () {
    char *str1, *str2, *str3;

    str1 = (char *)malloc(sizeof (char));
    str2 = (char *)malloc(sizeof (char));
    str3 = (char *)calloc(2, sizeof (char));

    printf ("Entre com uma string:\n");
    fflush(stdin);
    fgets(str1,50,stdin);
    *(str1+(StrLen(str1))-1) = 0;

    printf ("Entre com uma string:\n");
    fflush(stdin);
    fgets(str2,50,stdin);
    *(str2+(StrLen(str2))-1) = 0; // Remove o \n

    StrCat(str3, str1);
    StrCat(str3, str2);
    printf ("Voce digitou: %s\n",str3);

    printf("O tamanho da string concatenada e: %d\n", StrLen(str3));

    printf("StrCmp: %d\n", StrCmp(str1, str2));
    printf("%d", strcmp(str1, str2));

    free(str1);
    free(str2);
    free(str3);

    return(0);
}

int StrCmp (char *string1, char *string2) {
    while(*string1 && (*string1 == *string2)) {
        string1++;
        string2++;
    }
    return *string1 - *string2;
}

int StrLen (char *string) {
    int num = 0;
    while(*(string + num) != '\0') {
        num ++;
    }
    return num;
}

char* StrCat (char *destino, char *origem) {
    int i = StrLen(destino);
    int j;
    int tamanho_origem = StrLen(origem);

    for (j = 0; j < tamanho_origem ; ++j) {
        destino[i + j] = origem[j];
    }

    destino[i + j] = '\0';

    return destino;
}