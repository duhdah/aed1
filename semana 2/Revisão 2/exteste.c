#include <stdio.h>

int main(){

    int t, j = 1, *p, *g;
    t = 5;
    p = &t; // p aponta para t
    j = 3;
    g = &j; // g aponta para j

    *p = (*g + t) * 2;
    printf("*p = %d\n",*p);
    // O valor de t para a ser o valor de (j + t)*2, que é 16.

    *g = 4;
    printf("j = %d\n",j);

    printf("*p = %d\n",*p);

    g = p;
    // g passa a pontar para quem p aponta (t)

    for(j = 0; j < 2; j++){
        *g = t*j + 1;
        // t = t*j +1;
    }
    // j = 0 -> t = 16*0 + 1 = 1;
    // j = 1 -> t = 1*1 + 1 = 2;

    printf("t = %d",t);


}