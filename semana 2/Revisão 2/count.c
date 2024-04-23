#include <stdio.h>
#include <stdlib.h>

int main(){
    int count, q, *m;

    m = &count; // recebe endereço de count
    printf("Informe count =");
    scanf("%d",&count); //armazena no endereço de count
    q = *m; // recebe valor apontado por m
    printf("m=%p\n",m); // %p imprime ponteiro (endereço apontado)
    printf("q=%d\n",q);
    printf("m aponta para %d\n\n",*m); // conteudo apontado por m

    return 0;

/*
    ex:
        count = 20;
        m = 0022FF74;
        q = 20;
        m aponta para 20.
*/

}