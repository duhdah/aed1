#include <stdio.h>
#include <stdlib.h>

int main(){

    // ATRIBUIÇÕES COM PONTEIROS:

    // Um ponteiro pode ser usado no lado direito da atribuição para passar o valor para outro ponteiro.

    int x = 200, *p1, *p2;

    p1 = &x;
    // p1 aponta para x.

    p2 = p1;
    // p2 recebe p1 e também passa a apontar para x.

    printf("x-%d,p1=%p e p2=%p\n",x,p1,p2); // Valor de x e endereço dos ponteiros
    printf("x-%d,p1=%d e p2=%d\n",x,*p1,*p2); // Valores

    // Saida:
    //      x-200,p1=0061FF14 e p2=0061FF14
    //      x-200,p1=200 e p2=200
    


}