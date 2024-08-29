#include <stdio.h>
#include <stdlib.h>

// Complexidade: O(n log n)
// Mesmo no melhor caso, precisa dividir o array. Então, continua sendo n log n.
// No pior caso, o mesmo processo é feito. Então, é sempre n log n.

// Custo de memória: O(n) se implementado com listas ligadas 

// Pode ter processamento paralelo. Nesse caso, na hora de dividir no merge sort, é possível dividir uma recursão para cada núcleo do processador.
// A mesclagem também pode ser feita paralelamente.

int *merge_sort(int *array, int size);
int *merge(int *esquerda, int *direita, int tamEsq, int tamDir);
void printArray(int arr[], int size);


// Função principal do Merge Sort
// Como a função vai dividindo n a cada chamada, o comportamento dela é O(log n)
int *merge_sort(int *array, int size) {
    if(size < 2) return array;

    int *esquerda, *direita, *resultado;
    int meio = size/2;

    esquerda = (int *)malloc(sizeof(int) * meio);
    direita = (int *)malloc(sizeof(int) * (size - meio));

    for(int i = 0; i < meio; i++){
        esquerda[i] = array[i];
    }
    for(int i = meio; i < size; i++){
        direita[i - meio] = array[i];
    }

    esquerda = merge_sort(esquerda, meio);
    direita = merge_sort(direita, size - meio);

    resultado = merge(esquerda, direita, meio, size - meio);
    free(esquerda);
    free(direita);
    return resultado;
}


// Função para mesclar duas metades
// Dentro do merge, a função precisa percorrer a array inteira, ou seja O(n)
// Como a função merge é chamada log n vezes, a complexidade do merge é O(n log n)

int *merge(int *esquerda, int *direita, int tamEsq, int tamDir) {
    int *resultado =  (int *)malloc(sizeof(int) * (tamEsq + tamDir));
    int iEsq = 0, iDir = 0;
    while(iEsq < tamEsq || iDir < tamDir){
        if(iEsq < tamEsq && iDir < tamDir){
            if(esquerda[iEsq] < direita[iDir]){
                resultado[iEsq + iDir] = esquerda[iEsq];
                iEsq++;
            } else {
                resultado[iEsq + iDir] = direita[iDir];
                iDir++;
            }
        }
        else {
            if(iEsq < tamEsq){
                resultado[iEsq + iDir] = esquerda[iEsq];
                iEsq++;
            } else {
                resultado[iEsq + iDir] = direita[iDir];
                iDir++;
            }
        }
    }
    return resultado;
}



// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função principal para testar o Merge Sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, arr_size-1);

    int *sortedArray = merge_sort(arr, arr_size);

    printf("Array ordenado: \n");
    printArray(sortedArray, arr_size);
    return 0;
}


