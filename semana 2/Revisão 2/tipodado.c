#include <stdio.h>

int main(){

    // Por que ponteiros tem tipos?
    // Por causa do espaço que cada tipo ocupa na memória.
    // ex. char ocupa 1 byte, int ocupa 2 bytes, float ocupa 4 bytes.
    // Dá erro ao tentar passar float para int por isso.
    // O nome da variavel diz onde ela começa e o tipo de dado diz onde ela termina.

    // Supondo que end. 4 = 'U', end. 5 = 'F', end. 6 = 'F' e end. 7 = 'S':
        char *cUFFS = "UFFS"; // Onde o ponteiro aponta para o endereço 4.

        printf("%c",*cUFFS);
        // Imprime 'U'.

        cUFFS++;
        // O ponteiro passa a apontar para o próximo bloco/endereço (5).

        printf("%c",*cUFFS);
        cUFFS++;
        printf("%c",*cUFFS);
        cUFFS++;
        printf("%c",*cUFFS);
        
        // Toda a palavra tera sido imprimida.

        cUFFS -= 3;
        // Volta para o inicio da string.

        printf("%s",cUFFS);
        // Imprime toda a string até achar o \0.
        // Se não tiver o terminador, ele imprime toda a memoria até achar um \0.

}