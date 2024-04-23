#include <stdio.h>

int main(){

    // Adição e subtração de ponteiros:

    // É possível somar/subtrair inteiros de ponteiros.
    // O valor do ponteiro vai mudar de acordo com o número de bytes ocupados pelo tipo base.

    // Assumindo que int ocupa 4 bytes, se temos:
    int *p1 = 2000; // endereço do ponteiro para int 'p1' é 2000.

    p1++; // O valor de p1 passa a ser 2004.

    p1--; // O valor de p1 volta a ser 2000.

    p1 = p1 + 5; // p1 passa a apontar pra 2000 + (5 * 4).

    // OBS: ++ e -- só funciona quando os dados são do mesmo tipo.
    // Se for uma sequência de int e float, por exemplo, tem que cuidar quantos blocos pular.

}