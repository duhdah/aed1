#include <stdio.h>

struct Empregado{
    int cod;
    unsigned int salario;
};

int main(){

    struct Empregado EP, *pEP;
    // OBS: 
    // EP alocou um espaço suficiente para todos elementos da struct
    // pEP só alocou o suficiente para caber um endereço de memoria

    EP.cod = 1;
    EP.salario = 1000;

    pEP = &EP;

    pEP->cod = 2;
    // Operador ->: Equivale a (*pEP).cod
    // Trocou o valor do codigo do Empregado EP para 2

    printf("%d",&pEP->salario);

    return 0;
}