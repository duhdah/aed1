
#include <stdio.h>

int main(){

    // VARIAVEIS:

    // Cada variavel possui um endereço que pode acessado simbolicamente por seu nome.
    // Variaveis possuem nome, tipo (capacidade de armazenamento) e endereço.

    int num = 0;
    // O nome é "num", o tipo é int, o endereço é 3 (por exemplo) e o valor é 0.

    int num2;
    // O nome é "num2", o tipo é int, o endereço é 6 (por exemplo) e o valor é indefinido (lixo de memoria).

    num2 = 5;
    // No endereço da variavel "num2", é colocado 5.

    int *num3 = 6;
    // O nome é "num3", é um ponteiro do tipo int, o endereço é 1 (por exemplo) e o valor é 6.
    // O valor que ele contem nao é um inteiro, mas sim um endereço de memoria (6).

    *num3 = 7;
    // O nome da variavel é só num3. O * representa uma operação.
    // O 7 vai para o endereço 6, que é o conteúdo da variável num3.
    // Agora, num2 = 7.
    
}
