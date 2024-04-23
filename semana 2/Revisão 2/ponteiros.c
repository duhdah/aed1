#include <stdio.h>
#include <stdlib.h>

int main(){

        // PONTEIROS:

        // Declaração: 
        //      tipo *nome do ponteiro

        // Operadores:
        //      &: operador unário que devolve o endereço de memória do operando.
        //         ex. int num.
        //             &num retorna o enderço de num.
        //      *: operador unário que devolve o valor da variável localizada no endereço que o segue.
        //         ex. int *num.
        //             *num retorna o valor do endereço apontado por num.

        //      OBS: Na declaração, * é usado para informar que a variável é do tipo ponteiro. Não é um operador.

        float *f; // f é ponteiro para variáveis do tipo float.
        int *i; // i é ponteiro para variáveis do tipo int.
        char a, b, *p, c, *q; // variáveis de tipos diferentes podem ser declaradas juntas.

        // A função do * depende do contexto (pode ser multiplicação também).

        int count, q, *m;
        count = 10;
        m = &count;
        q = *m;

        // 'm' recebe o endereço da variável 'count'.
        // 'q' recebe o valor armazenado no enderçeo de 'm'.

}