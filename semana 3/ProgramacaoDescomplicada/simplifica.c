    /*
    Faça uma função chamada ‘simplifica’ que recebe como parâmetro o numerador e o denominador de uma fração. 
    Esta função deve simplificar a fração recebida dividindo o numerador e o denominador pelo maior fator possível. 
    Por exemplo, a fração 36/60 simplifica para 3/5 dividindo o numerador e o denominador por 12. A função deve modificar as 
    variáveis passadas como parˆ ametro.
    */

#include <stdio.h>
#include <math.h>

void Simplifica ( int *num, int *den );

int main () {
    int a = 30, b = 60, *pa, *pb;
    int a, b, *pa, *pb;
    printf( "Digite a fracao: " );
    scanf( "%d/%d" , &a, &b );
    pa = &a;
    pb = &b;
    Simplifica ( pa, pb );
    printf( "Fracao simplificada: %d/%d" , a , b );
    return 0;
}

/*
==================== 
Simplifica
  Pega o endereco de 2 numeros (numerador e denominador de uma fracao) e muda o conteudo deles para a forma simplificada, se possivel
  ====================
*/

void Simplifica ( int *num, int *den ) {
    int menor;
    if( *num < *den ) { menor = *num; } else { menor = *den; };
    while(menor > 0){
      if( ( ( (*num) % menor ) == 0 ) && ( ( (*den) % menor) == 0 ) ) { 
        *num = (*num)/menor;
        *den = (*den)/menor;
        break;
      }
      menor--;
    }
}