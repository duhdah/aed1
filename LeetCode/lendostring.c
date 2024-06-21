#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *string,a,*p;
    printf("Digite a sua frase:");
    string = (char *)malloc(sizeof(char));
    p = string;
    while(((a=getchar())!='\n') && a!=EOF){
        *p=a;
        realloc(string,sizeof(char)*strlen(string));
        p++;
    }
    *p = '\0';
    printf("String lida: %s",string);
    free(string);
    return 0;
}