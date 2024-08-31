#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria ( int *vetor, int n, int alvo );
void InsertionSort ( int *dificuldades, int *lucros, int n );
int MaiorLucro ( int habilidade, int *dificuldades, int *lucros, int n );
int maxProfitAssignment ( int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize);

// OBS: O código feito em aula funciona! Esse foi só uma tentativa de otimizar :^)

/*
==============================================================
BuscaBinaria

    Implementação do algoritmo de busca binária. Foi usado 
    para encontrar o indice da maior dificuldade que o
    trabalhador consegue lidar no indice ordenado de
    dificuldades. A complexidade é O(log n).
==============================================================
*/

int BuscaBinaria ( int *vetor, int n, int alvo ) {
    int esq = 0, dir = n - 1;
    while ( esq <= dir ) {
        int meio = esq + ( dir - esq ) / 2;
        if (vetor [ meio ] <= alvo ) {
            esq = meio + 1; 
        } else {
            dir = meio - 1; 
        }
    }
    return dir;
}

/*
==============================================================
MaiorLucro

    Chama a função busca binária para saber até qual índice
    deve iterar. Passa do início do vetor até esse indíce
    comparando os valores do lucro do índice correspondente
    e retorna o maior deles. Tem uma complexidade dominante
    de O(n) por percorrer o vetor até o valor do índice.
==============================================================
*/

int MaiorLucro ( int habilidade, int *dificuldades, int *lucros, int n ) {
    int indice = BuscaBinaria ( dificuldades, n, habilidade );
    if ( indice == -1 ) return 0; 
    int lucro = 0;
    for ( int i = 0; i <= indice; i++) {
        if ( lucros [ i ] > lucro ) {
            lucro = lucros [ i ];
        }
    }
    return lucro;
}

/*
==============================================================
InsertionSort

    Implementação do algoritmo de ordenação Insertion Sort.
    Foi usado para ordenar o vetor de dificuldades para ficar
    mais simples de descobrir qual a mais rentável e ir
    modificando ao mesmo tempo o vetor de lucros. A
    complexidade no pior caso é de O(n²).
==============================================================
*/

void InsertionSort ( int *dificuldades, int *lucros, int n ) {
    for (int j = 1; j < n; j++) {
        int i = j - 1;
        int tempDif = dificuldades[j];
        int tempLucros = lucros[j];
        while ( ( i >= 0 ) && ( dificuldades [ i ] > tempDif ) ) {
            dificuldades [ i + 1 ] = dificuldades [ i ];
            lucros [ i + 1 ] = lucros [ i ];
            i--;
        }
        dificuldades [ i + 1 ] = tempDif;
        lucros [ i + 1 ] = tempLucros;
    }
}

/*
==============================================================
maxProfitAssignment

    A função principal do LeetCode. Ordena o vetor de
    dificuldades chamando InsertionSort, depois vai somando
    à variável lucro os maiores lucros possíveis de cada
    trabalhador, que são encontrados pela MaiorLucro. A
    complexidade dominante fica O(n²) devido ao Insertion
    Sort.

    OBS: O nome da função ficou em minúsculo para poder
    testar o código direto no LeetCode.
==============================================================
*/

int maxProfitAssignment ( int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize ) {
    int lucros = 0;
    InsertionSort ( difficulty, profit, difficultySize );
    for ( int i = 0; i < workerSize; i++ ) {
        lucros += MaiorLucro ( worker [ i ], difficulty, profit, difficultySize );
    }
    return lucros;
}

// Para testar os casos escolhidos fora do LeetCode:
/*
int main ( ) {

    int difficulty[] = {2, 4, 6, 8, 10};
    int profit[] = {10, 20, 30, 40, 50};
    int worker[] = {4, 5, 6, 7};
    // Output: 100

    int difficulty[] = {85, 47, 57};
    int profit[] = {24, 66, 99};
    int worker[] = {40, 25, 25};
    // Output: 0

    int difficulty[] = {1, 3, 4, 7, 3, 4, 8};
    int profit[] = {4, 6, 5, 7, 5, 3, 8};
    int worker[] = {1, 2, 8, 5};
    // Output: 22

    int difficultySize = sizeof ( difficulty ) / sizeof ( difficulty [ 0 ] );
    int profitSize = sizeof ( profit ) / sizeof ( profit [ 0 ] );
    int workerSize = sizeof ( worker ) / sizeof ( worker [ 0 ] );

    int lucroMaximo = MaxProfitAssignment ( difficulty, difficultySize, profit, profitSize, worker, workerSize );

    printf ( "Lucro maximo: %d\n", lucroMaximo );

    return 0;

}
*/