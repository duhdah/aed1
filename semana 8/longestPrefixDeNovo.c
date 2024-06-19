#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Já tinha feito esse no Leet na semana passada, mas resolvi fazer o código completo para debugar e compreendê-lo melhor.
*/

char* longestCommonPrefix(char** strs, int strsSize);

int main(){
    int n;
    char **strs,  *prefixo;
    printf("Digite o numero de strings: \n");
    do{
        scanf("%d",&n);
    }while(n<=0);
    getchar();
    strs = (char **)malloc(n * sizeof(char *));
    printf("Digite as %d strings: ",n);
    for(int i = 0; i < n; i++){
        strs[i] = (char *)malloc(sizeof(char) * 50);
        fgets(strs[i],50,stdin);
        strs[i][strcspn(strs[i],"\n")] = '\0';
    }
    prefixo = longestCommonPrefix(strs,n);
    printf("Prefixo comum: %s",prefixo);
    
    /* printf("Strings lidas: ");
    for(int i = 0; i < n; i++){
        puts(strs[i]);
    }*/
    for(int i = 0 ; i < n; i++) free(strs[i]);
    free(strs);
    if(prefixo) free(prefixo);
}

char* longestCommonPrefix(char** strs, int strsSize){
    char *primeira = strs[0];
    int tam = strlen(primeira);

    for(int i = 1; i < strsSize; i++){
        int j = 0;
        while(j < tam && strs[i][j] == primeira[j]) j++;
        tam = j;
        // quando o tamanho é definido aqui, ele interfere na proxima palavra a ser comparada pois o while só funciona
        // enquanto j < tam, então, se ele encontrou primeiro j = 4 e depois j = 1, as condições do while só podem ser aceitas
        // uma vez ou nenhuma, o que limita o maior prefixo comum ao numero menor encontrado nas comparações.
        if(tam == 0) return strdup("");
    }


    char *prefixo = (char *)malloc(sizeof(char) * (tam + 1));
    strncpy(prefixo,primeira,tam);
    prefixo[tam] = '\0';

    return prefixo;
}