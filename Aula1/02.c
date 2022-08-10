#include <stdio.h>
#include <stdlib.h>

int StrLen (char *string) { // Retorna o tramanho da string
    int num = 0;
    while(*string) {
        num ++;
        string++;
    }
    return num;
}

int StrEnd(char *s, char *t) {
    int i = StrLen(s)-StrLen(t);
    
    while(*(s+i) != '\0') {
        if(*(s+i) != *t) return 0;
        i++;
        t++;
    }
    return 1;
}

int main()
{
    char *str1, *str2;
    
    str1 = (char *)malloc(sizeof(char));
    str2 = (char *)malloc(sizeof(char));
    
    printf("Entre com a primeira string:\n");
    fflush(stdin);
    fgets(str1, 50, stdin);
    
    printf("Entre com a segunda string:\n");
    fflush(stdin);
    gets(str2, 50, stdin);
    
    int n = StrEnd(str1, str2);
    printf("\n%d", n);
    
    free(str1);
    free(str2);
    return 0;
}
