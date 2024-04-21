#include <stdio.h>
#include <stdlib.h>

int main(){

    // Depois de declarado um vetor, nao da para mudar o valor
    // ex. int notaAlunos[3];
    //     int notaAlunos[4];

    // É possível perguntar antes o número de alunos e depois declarar o vetor, mas não é recomendável
    // ex. int nNumAlunos
    //     scanf("%d",&nNumAlunos);
    //     int notaAlunos[nNumAlunos];

    int nNumAlunos;
    scanf("%d",&nNumAlunos); // Pergunta o numero inicial de alunos

    int *notaAlunos;
    notaAlunos = malloc(sizeof(int)*nNumAlunos); // Aloca dinamicamente um buffer para n 
    
    //Se o numero de alunos mudar:
    // ex. nNumAlunos = 4;
    //     notaAlunos = malloc(sizeof(int)*nNumAlunos);
    // PROBLEMA: A região da memória ocupada pelo ponteiro anteriormente se perdeu! (Memory Leak)
    // SOLUÇÃO: Antes, liberar o buffer.

    free(notaAlunos);
    nNumAlunos = 4;
    notaAlunos = malloc(sizeof(int)*nNumAlunos);

    // Para cada malloc, usar um free.
    // Testar sempre se o malloc dá NULL. Se der, não há mais memória para alocar.
    // ex. int *teste = malloc(sizeof(int));
    //     if(!teste){
    //          printf("Erro! Falta de memoria.");
    //          return -1;
    //      }

    // OBS: Sem casting, o malloc sempre retorna um ponteiro para void.
    // ex. notaAlunos = malloc(sizeof(int)*nNumAlunos);
    // Dá um warning compilar sem o casting.
    // O correto seria notaAlunos = (int *)malloc(sizeof(int)*nNumAlunos);
    // Sempre usar casting!

}