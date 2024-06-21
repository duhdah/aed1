#include <stdio.h>
#include <math.h>

int main(){

    // Divisao de int com resto e comparacao com float:

    int i = 3;
    printf("INT:\n");
    printf("i: %d\n",i);
    printf("i/2: %d\n",i/2);
    printf("ceil(i/2): %d\n",(int)ceil(i/2));

    i = ceil(i/2);

    float j = 3;
    printf("FLOAT:\n");
    printf("j: %.1f\n",j);
    printf("j/2: %.1f\n",j/2);
    printf("ceil(j/2): %.1f\n",ceil(j/2));

    int k = 3;

    j = ceil(k/2);
    printf("j sem casting: %.f\n",j);

    j = ceil((float)k/2);
    printf("j com casting: %.f\n",j);

    printf("j e maior que i: %d",j>i);

    return 0;

}