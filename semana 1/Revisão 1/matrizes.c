#include <stdio.h>
#include <stdlib.h>

int main(){

    // Os elementos de um vetor podem ser acessados de duas maneiras:
    //      1. Notação de vetores: p[i];
    //      2. Notação de ponteiros: *(p+i);

    // Alocando um vetor de inteiros:
    int *p1;
    p1 = (int *)malloc(4*sizeof(int));

    int *p2;
    p2 = (int *)malloc(4*sizeof(int));

    // Os endereços dos ponteiros p1 e p2 não são sequenciais, mas os endereços dos elementos de cada um dos vetores são.

    // MATRIZES: Usar ponteiros para ponteiros.
    int nLinhas;
    int **p = (int **)malloc(sizeof(int *)* nLinhas);
    
    // O malloc vai reservar um numero nLinhas de ponteiros para inteiros.
    // Um ponteiro aponta para o endereço de um ponteiro que contém outro endereço dentro.
    // Vetor de vetores!
    // Precisa de um free para cada linha e para a lista de ponteiros criados (o vetor de vetores).

    // Exemplo da alocação de memória para matrizes:

    int **M;
    int i, ncols = 5, nrows = 6;
    M = (int **)malloc(nrows*sizeof(int *));
    for(i=0;i<nrows;i++){
        M[i] = (int*)malloc(ncols*sizeof(int));
    }

    // Agora, é possível acessar M[i][j].
    // Para desalocar essa matriz:

    for(i=0; i< nrows; i++){
        free(M[i]);
    }
    free(M);

    // Calloc: pede o numero de elementos e o tamanho deles.
    //      void *calloc(size_t num, size_t size);

    // Realloc: redimensiona um buffer. Pede o buffer e o novo tamanho.
    //      void *realloc(void *pont, size_t size);
    // OBS! O realloc pode fazer os elementos trocarem de endereço.
    // Se o buffer aumentar, os novos endereços irão conter lixo de memória. 
}
