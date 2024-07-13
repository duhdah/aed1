
// 1º código funcional: Usando pilha! 
// Funcionou com 28 ms de runtime e 12.82 MB

/*
=============================================================================
MaximumGain

    A funcao encontra substrings 'ab' ou 'ba' em uma ordem definida pela pontuação
    que cada uma vale e remove-as de modo a maximizar a pontuação obtida.
=============================================================================
*/

int MaximumGain ( char* s, int x, int y ) {

    int pontos = 0;
    int tam = strlen ( s ) ;
    char* pilha = ( char * ) malloc ( tam + 1 ) ;
    int topo = -1;

    if ( x > y ) {
        for ( int i = 0; i < tam; i++ ) {
            if ( topo >= 0 && pilha[topo] == 'a' && s[i] == 'b' ) {
                topo--; 
                pontos += x;
            } else {
                pilha[++topo] = s[i];
            }
        }
    } else {
        for ( int i = 0; i < tam; i++ ) {
            if ( topo >= 0 && pilha[topo] == 'b' && s[i] == 'a' ) {
                topo--;
                pontos += y;
            } else {
                pilha[++topo] = s[i];
            }
        }
    }

    int novoTam = topo + 1;
    topo = -1;

    if ( x > y ) {
        for ( int i = 0; i < novoTam; i++ ) {
            if ( topo >= 0 && pilha[topo] == 'b' && pilha[i] == 'a' ) {
                topo--; 
                pontos += y;
            } else {
                pilha[++topo] = pilha[i];
            }
        }
    } else {
        for ( int i = 0; i < novoTam; i++ ) {
            if ( topo >= 0 && pilha[topo] == 'a' && pilha[i] == 'b' ) {
                topo--;
                pontos += x;
            } else {
                pilha[++topo] = pilha[i];
            }
        }
    }

    strncpy ( s, pilha, topo + 1 );
    s[topo + 1] = '\0';

    free ( pilha );
    return pontos;

}




// 2º código funcional (Extra): Versão modificando a string, sem usar pilha
// Funcionou com 62 ms de runtime e 11.14MB de memória

int RemoveSubstring ( char* string, const char* substring, int pontosPorSubstring );
int MaximumGain ( char* s, int x, int y );

/*
=============================================================================
MaximumGain

    A funcao encontra substrings 'ab' ou 'ba' em uma ordem definida pela pontuação
    que cada uma vale e remove-as de modo a maximizar a pontuação obtida.
=============================================================================
*/

int MaximumGain ( char* s, int x, int y ) {

    int totalDePontos = 0;

    if (x > y) {
        
        totalDePontos += RemoveSubstring ( s, "ab", x );
        totalDePontos += RemoveSubstring ( s, "ba", y );

    } else {

        totalDePontos += RemoveSubstring ( s, "ba", y );
        totalDePontos += RemoveSubstring ( s, "ab", x );

    }

    return totalDePontos;

}

/*
=============================================================================
RemoveSubstring

    A funcao remove uma das substrings 'ab' ou 'ba' passada como parâmetro da
    string e contabiliza os pontos conforme a remoção das ocorrências.
=============================================================================
*/

int RemoveSubstring ( char* string, const char* substring, int pontosPorSubstring )  {

    int totalPoints = 0;
    int tam = strlen ( string );
    int escrita = 0;

    for ( int leitura = 0; leitura < tam; leitura++ ) {

        string[escrita++] = string[leitura];

        if ( escrita >= 2 && strncmp ( &string [ escrita - 2 ], substring, 2 ) == 0 ) {

            escrita -= 2;
            totalPoints += pontosPorSubstring;

        }

    }

    string[escrita] = '\0';
    return totalPoints;

}