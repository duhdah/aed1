#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *reallocD(int *b, int n);

int main(){
    
    // Exercicio: Faça a implementação da função realloc, você deve utilizar a função malloc para isso.
    //      void *realloc(void *pont, size_t newSize);
    // Dica: void *memcpy(void *destination, const void * source, size_t num);

    int *inteiros;
    inteiros = (int *)malloc(sizeof(int)*5);
    for(int i = 0; i < 5; i++){
        *(inteiros+i) = 1+i;
    }
    printf("Tamanho inteiros: %d ",sizeof(inteiros));
    realloc(inteiros, 6);
    *(inteiros+5) = 6;
    for(int i = 0; i < 6; i++){
        printf("%d ",*(inteiros+i));
    }
    free(inteiros);
    return 0;
}

void *reallocD(int *b, int n){
    int *p;
    p = malloc(sizeof(b)+n*sizeof(int));
    memcpy(p,b,sizeof(b)/sizeof(int)+n*sizeof(int));
    free(b);
    return p;
}