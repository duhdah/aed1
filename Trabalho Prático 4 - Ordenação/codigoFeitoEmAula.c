int buscaBinaria ( int *vetor, int n, int alvo );
void insertionSort ( int *dificuldades, int *lucros, int n );
int maiorLucro ( int habilidade, int *dificuldades, int *lucros, int n );


int maxProfitAssignment ( int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize ) {

    int lucros = 0;
    insertionSort ( difficulty, profit, difficultySize );

    for ( int i = 0; i < workerSize; i++ ) {
        lucros += maiorLucro ( worker [ i ] , difficulty, profit, difficultySize );
    }

    return lucros;

}

int maiorLucro ( int habilidade, int *dificuldades, int *lucros, int n ) {

    int lucro = 0;
    int indiceDificuldades = 0;

    while ( ( indiceDificuldades < n ) && ( dificuldades [ indiceDificuldades ] <= habilidade ) ) {
        if ( lucros [ indiceDificuldades ] > lucro ) {
            lucro = lucros [ indiceDificuldades ];
        }
        indiceDificuldades++;
    }

    return lucro;

}

void insertionSort ( int *dificuldades, int *lucros, int n ) {

    for ( int j = 1; j < n; j++ ) {

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