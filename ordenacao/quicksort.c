#include <stdio.h>

// Usa um pivô para que os elementos menores que ele fiquem a esquerda e os menores, à direita. Depois, o pivô é colocado na posição correta.
// O vetor terá sido dividido em duas metades: Uma com elementos maiores que o pivô e outra com menores.
// Novamente, pivôs são escolhidos e as sublistas são ordenadas de acordo com seus pivôs.
// A escolha do pivô é aleatória.

// Complexidade: O(n log n) no caso médio/melhor caso e O(n²) no pior caso.
// Nesse caso, o pivô sempre divide o array em uma parte com tamanho 0 e outra com tamanho n-1.
// Isso resulta em uma soma de comparações de 1 a n-1 n vezes, o que resulta na complexidade O(n²).
// Geralmente mais rápido que bubble sort e insertion sort.

// Com o pivô ideal, a complexidade se assemelha a do merge sort (n log n). Mas em questão de espaço, é melhor que o merge sort.
// O quick sort é in-place, ou seja, não precisa de espaço adicional para ordenar o array. O merge sort requer tamanho adicional
// proporcional ao tamanho do array. No caso do quick sort, a complexidade de espaço tende a ser O(log n).

// IMPORTANTE:
// A troca só acontece quando o elemento da esquerda é maior que o pivô e o a direita é menor que o pivô!
// ex: 2 4 1 3 com pivô 3: a troca correta é 4 e 1

void Quicksort (int data[], int left, int right){
    int mid, tmp, i, j;
    i = left;
    j = right;
    // Pivo: Elemento do meio
    mid = data[(left + right) / 2];
    do {
        while (data[i] < mid){
            i++;
        }
        while(mid < data[j]){
            j++;
        }
        if(i <= j){
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        }
    } while(i <= j);
    if (left < j){
        Quicksort (data, left, j);
    }
    if (i < right){
        Quicksort (data, i, right);
    }
}