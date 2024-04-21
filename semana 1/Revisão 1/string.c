#include <stdio.h>
#include <stdlib.h>

int main(){

    // Para armazenar uma string:
    //      char nome[50];
    // Mas e se o nome for Ana? Desperdício de memória!

    // Alocando dinamicamente:

    int nTamanhoDoNome;
    printf("Digite o tamanho do nome: ");
    scanf("%d",&nTamanhoDoNome);
    char *nome = (char *)malloc(sizeof(char)*nTamanhoDoNome);

}