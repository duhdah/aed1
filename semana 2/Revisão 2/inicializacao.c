#include <stdio.h>

int main(){

    // Inicializar ponteiros em NULL para evitar segmentation fault.

    // Fazem a mesma coisa:
    // Na memoria, é sequencial

    // Ex 1:

    float matrx[50][50];
    int i,j;
    for (i=0;i<50;i++){
        for(j=0;j<50;j++){
            matrx[i][j]=0.0;
        }
    }
    return(0);

    // Ex 2:

    float matrx[50][50];
    float *p = NULL;
    int count;
    p=&matrx[0][0];
    for (count = 0; count < 2500; count ++){
        *p = 0.0;
        p++;
    }
    return(0);
}
