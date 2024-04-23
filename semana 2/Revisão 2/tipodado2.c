#include <stdio.h>

int main(){

    int vNum[3] = {0,1,2};
    // vNum é do tipo int[3], está no endereço 0 e tem armazenado o valor 0.

    int *pNum;
    pNum = &vNum;
    // pNum é do tipo ponteiro pra int, está no endereço 6 e tem armazenado o valor 0.

    printf("%d ",vNum[0]);
    printf("%d ",*pNum);
    printf("\n");
    // Imprimem 0.

    pNum++; 
    // O valor de pNum passa a ser 2, pois int ocupa 2 bytes. Passou para o proximo int.

    printf("%d ",vNum[1]);
    printf("%d ",*pNum);
    printf("\n");

    pNum++;

    printf("%d ",vNum[2]);
    printf("%d ",*pNum);



}