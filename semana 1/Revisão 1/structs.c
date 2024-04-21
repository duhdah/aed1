#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

int main(){
    Pessoa *p; // Cria um ponteiro para a struct, mas nao aloca ela.
    p = (Pessoa *)malloc(sizeof(Pessoa)); // Aloca espaco para as informacoes de Pessoa.

    // Lendo os dados:
    printf("Nome: "); scanf("%s",&(*p).nome); // Não quer o que está no ponteiro, mas para onde ele está apontado.
    printf("Idade: "); scanf("%s",&(*p).idade);
    printf("Altura: "); scanf("%s",&(*p).altura);
    // OBS: Precisa de parênteses, pois o ponto (.) tem prioridade maior que o *.

    // Outra forma de escrever &(*p).nome:
    //      p->nome

    // Imprimindo os dados:
    printf("Nome: %s\n",(*p).nome);
    printf("Idade: %s\n",(*p).idade);
    printf("Altura: %s\n",(*p).altura);

    // Para criar um buffer com mais pessoas:
    // ex. int nNumPessoas;
    //     printf("Quantas pessoas?");
    //     scanf("%d",&nNumPessoas);
    //     Pessoa *p;
    //     p = (Pessoa *)malloc(sizeof(Pessoa)*nNumPessoas);

    return 0;

}