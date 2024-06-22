
// OBS: Esse codigo foi feito em casa para poder testar no VSCode.

#include <stdio.h>
#include <stdbool.h>

bool LemonadeChange( int* bills, int billsSize );

int main ( ) {
    
    int clientes;
    
    printf( "Digite o numero de clientes: " );
    scanf( "%d" ,&clientes );
    
    int notas[ clientes ];
    printf( "Digite as notas dadas pelos clientes: " );
    for ( int i = 0; i < clientes; i++ ) {
        scanf( "%d", &notas[i] );
    }
    
    bool troco = LemonadeChange( notas, clientes );
    if ( troco ) {
        printf( "Todos clientes receberam troco adequadamente.\n" );
    } else {
        printf( "Nao foi possivel dar troco para algum cliente.\n" );
    }

    return 0;

}


/* ================================================================================================
LemonadeChange  

    A função retorna um valor booleano que indica se é possível dar troco a todos os clientes 
    que compraram uma limonada que custa 5 reais usando notas de 5, 10 e 20 reais nas compras.

================================================================================================ */

bool LemonadeChange( int* bills, int billsSize ) {

    int num5 = 0, num10 = 0;

    for ( int i = 0; i < billsSize; i++ ) {
        if ( bills[i] == 5 ) {
            num5++;
        }
        if ( bills[i] == 10 ) {
            if ( num5 == 0 ) {
                return false;
            }
            num5--;
            num10++;
        }
        if ( bills[i] == 20 ) {
            if ( num10 >= 1 && num5 >= 1 ) {
                num10--;
                num5--;
            } else if ( num5 >= 3 ) {
                num5 -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}

