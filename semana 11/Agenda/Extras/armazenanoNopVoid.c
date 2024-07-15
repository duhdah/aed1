#include <stdio.h>
#include <stdlib.h>

/*

Faça uma agenda com o seguinte menu:
1- Adicionar Pessoa (Nome, Idade, email)
2- Remover Pessoa
3- Buscar Pessoa
4- Listar todos
5- Sair

Não pode criar variáveis, funções que usem variáveis como parâmetros e structs.
Só podem ser declarados ponteiros que apontam para dentro de pBuffer.
Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
Implementar a base de dados da agenda usando lista duplamente ligada.
Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

*/

// ao percorrer pBuffer, como o ponteiro vai saber onde é o fim e onde é o começo?

void *pBuffer;

int main(){

    // Inicializa o pBuffer com o tamanho necessario pra 1 int:
    pBuffer = malloc(sizeof(int));

    // Lê um valor e coloca no pBuffer
    printf("Digite o primeiro valor inteiro do pBuffer: ");
    scanf("%d",(int *)pBuffer);
    printf("%d",*(int *)pBuffer);

    // Realloc para poder ler mais um inteiro
    realloc(pBuffer,2*sizeof(int));
    printf("Primeiro valor: %d\n",*(int *)pBuffer);

    // Um int ocupa 4 bytes, então mover 4 bytes pra frente dá espaço para ler um novo int
    pBuffer+=4;
    printf("Digite o segundo valor inteiro do pBuffer: ");
    scanf("%d",(int *)pBuffer);
    printf("Segundo valor: %d\n",*(int *)pBuffer);

    // Depois de armazenar um segundo valor, podemos voltar para o primeiro valor voltando 4 bytes
    pBuffer-=4;
    printf("Primeiro valor: %d\n",*(int *)pBuffer);
    return 0;


    // se nome ocupar 20 bytes, idade ocupar 4 bytes e email ocupar 20 bytes, pAgenda+=44 pode ser util para percorrer a agenda
    // dai guardar o numero de pessoas na agenda pode ajudar!

    /*
    void *pAgenda;
    pAgenda = malloc(20*sizeof(char)+sizeof(int)+20*sizeof(char)); ... ouuuu pAgenda = malloc(44);
    */


}