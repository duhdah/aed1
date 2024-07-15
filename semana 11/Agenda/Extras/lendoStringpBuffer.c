#include <stdio.h>
#include <stdlib.h>

void *pAgenda;
void *pBuffer;

int main(){
    pBuffer = malloc(sizeof(char) + 2*sizeof(int));
    pAgenda = malloc(sizeof(char));

    // Primeiro byte de pBuffer vai armazenar os caracteres do getchar()
    *(char *)pBuffer = 'a';

    // Os proximos 4 bytes de pBuffer armazenam a contagem de letras da palavra lida
    *(int *)(pBuffer+1) = 0;
    //printf("%c",*(char *)pBuffer); teste pra ver se armazenou!    

    printf("Digite a string: ");

    // Lendo a string:
    *(char *)pBuffer = getchar();
    while((*(char *)pBuffer != '\n') && (*(char *)pBuffer!= EOF)){
        *(char *)(pAgenda+*(int *)(pBuffer+1)) = *(char *)(pBuffer);
        *(int *)(pBuffer+1) = *(int *)(pBuffer+1) + 1;
        realloc(pAgenda, *(int *)(pBuffer + 1) * sizeof(char));
        if(pAgenda == NULL) return 0;
        *(char *)pBuffer = getchar();
    }
    *(char *)(pAgenda+*(int *)(pBuffer+1)) = '\0';

    // Variavel para fazer o for que vai imprimir a string:
    *(int *)(pBuffer+5) = 0;

    for(*(int *)(pBuffer+5) = 0; *(int *)(pBuffer+5) < *(int *)(pBuffer+1); *(int *)(pBuffer+5) = *(int *)(pBuffer+5) + 1){
        printf("%c", *(char *)(pAgenda+*(int *)(pBuffer+5)));
    }

    free(pAgenda);
    free(pBuffer);
    return 0;
}
