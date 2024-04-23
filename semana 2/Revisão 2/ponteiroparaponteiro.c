#include <stdio.h>

int main(){

    // Ponteiro para ponteiro:
    // Tem como valor um enderço de memoria que aponta para outro endereço de memoria.
    int n = 10, *pn, **pnn;
    pn = &n;
    pnn = &pn;

    printf("%d %d %d",n,*pn,**pnn);

}