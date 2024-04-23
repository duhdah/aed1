#include <stdio.h>
#include <stdlib.h>

int main() {
    int y = 3, x = 200, z = -94, *p1, *p2;

    printf("Conteudos iniciais:\n x - %d, y - %d, z - %d\n",x,y,z);

    p1 = &x; // p1 aponta para x.
    p2 = p1; // p2 recebe p1 e passa a apontar para x também.

    printf("\nx -  %d, p1 = %p e p2 = %p\n",x,p1,p2); // endereço de x.
    printf("Conteudos apontados: p1 = %d, p2 = %d\n",*p1,*p2); // conteudo de x.

    p1 = &y; // p1 aponta para y.
    *p2 = *p1; // elemento apontado: x recebe conteudo de y.

    printf("\nx -  %d, y = %d, p1 = %p e p2 = %p\n",x,y,p1,p2); // endereço de x e y.
    printf("Conteudos apontados: p1 = %d, p2 = %d\n",*p1,*p2); // conteudo de y.

    p1 = &z; // só p1 aponta para z.
    
    printf("\nx -  %d, y = %d, p1 = %p e p2 = %p\n",x,y,p1,p2); // endereço de z e y.
    printf("Conteudos apontados: p1 = %d, p2 = %d\n",*p1,*p2); // conteudo de z e y.


/*
    Saída:
            Conteudos iniciais:
        x - 200, y - 3, z - -94

        x -  200, p1 = 0061FF10 e p2 = 0061FF10
        Conteudos apontados: p1 = 200, p2 = 200

        x -  3, y = 3, p1 = 0061FF14 e p2 = 0061FF10
        Conteudos apontados: p1 = 3, p2 = 3

        x -  3, y = 3, p1 = 0061FF0C e p2 = 0061FF10
        Conteudos apontados: p1 = -94, p2 = 3

*/

    return 0;
}