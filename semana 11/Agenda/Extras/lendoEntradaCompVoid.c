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

void *pBuffer;

int main(){
    pBuffer = malloc(sizeof(int));
    printf("Digite a sua escolha:\n 1) Adicionar pessoa (Nome, idade, email)\n 2) Remover pessoa\n 3) Buscar pessoa\n 4) Listar todos\n 5) Sair\n Opcao: ");
    scanf("%d",(int *)pBuffer);
    //printf("%d",*(int *)pBuffer);
    if(*(int *)pBuffer == 1){
        printf("Adicionando pessoa...");
    }else if(*(int *)pBuffer == 2){
        printf("Removendo pessoa...");
    }else if(*(int *)pBuffer == 3){
        printf("Buscando pessoa...");
    }else if(*(int *)pBuffer == 4){
        printf("Listando pessoas...");
    }else if(*(int *)pBuffer == 5){
        printf("Fim do programa.");
        return(0);
    }
    return 0;
}