#include <stdio.h>
#include <stdlib.h>

void *pAgenda;
void *pBuffer;

/*
pBuffer[0] = getchar (char = 1 byte!)  -> pBuffer
pBuffer[1] = tamanho de uma palavra lida (int = 4 bytes)   -> pBuffer+1
pBuffer[2] = variavel para for/entrada do menu (int = 4 bytes)   -> pBuffer+5
pBuffer[3] = número de pessoas armazenadas na agenda. (int = 4 bytes) -> pBuffer+9
pBuffer[4] = total de bytes ocupados (int = 4 bytes) -> pBuffer+13
pBuffer[5] = variavel para for (int = 4 bytes) -> pBuffer+17
pBuffer[6] = posicao anterior do ponteiro (int = 4 bytes) -> pBuffer+21
pBuffer[7] = posicao seguinte do ponteiro (int = 4 bytes) -> pBuffer+25
pBuffer[8...] = tamanho dos nomes + emails (int = 4 bytes) -> a partir de pBuffer+29
    ideia: ler nome, colocar um & depois de ler o nome, ler email, colocar & depois de ler email, ler o numero.
*/

int main(){
    pBuffer = malloc(sizeof(char) + 7*sizeof(int));
    pAgenda = malloc(sizeof(char)); 

    *(int *)(pBuffer+5) = 0; // para ler a entrada:
    *(int *)(pBuffer+9) = 0; // armazena o total de pessoas na agenda
    *(int *)(pBuffer+13) = 0; // armazena o total de bytes lidos

    while(*(int *)(pBuffer+5) != 5){
        printf("Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n 5) Sair\nEntrada: ");
        scanf("%d",(int *)(pBuffer+5));
        getchar();
        // Adicionar pessoa:
        if(*(int *)(pBuffer+5) == 1){

            printf("Digite o nome: ");

            *(int *)(pBuffer+1) = 0; // tamanho da palavra

            *(char *)pBuffer = getchar();
            while((*(char *)pBuffer != '\n') && (*(char *)pBuffer!= EOF)){
                *(char *)(pAgenda+*(int *)(pBuffer+1)) = *(char *)(pBuffer);
                *(int *)(pBuffer+1) = *(int *)(pBuffer+1) + 1;
                *(char *)(pBuffer+1000) = realloc(pAgenda, (*(int *)(pBuffer + 1) + 1) * sizeof(char)); // Use um ponteiro temporário
                if (*(char *)(pBuffer+1000) == NULL) {
                    free(pAgenda); // Libere a memória alocada
                    return 0;
                }
                pAgenda = *(char *)(pBuffer+1000); // Atualize pAgenda com o ponteiro retornado por realloc
                *(char *)pBuffer = getchar();
            }
            *(char *)(pAgenda+*(int *)(pBuffer+1)) = '&';

            realloc(pBuffer, sizeof(pBuffer) + 4);
            if(pBuffer == NULL) return 0;
            *(int *)(pBuffer+1) = *(int *)(pBuffer+1) + 1;

            printf("Digite o email: ");

            *(char *)pBuffer = getchar();
            while((*(char *)pBuffer != '\n') && (*(char *)pBuffer!= EOF)){
                *(char *)(pAgenda+*(int *)(pBuffer+1)) = *(char *)(pBuffer);
                *(int *)(pBuffer+1) = *(int *)(pBuffer+1) + 1;
                *(char *)(pBuffer+1000) = (char *)realloc(pAgenda, (*(int *)(pBuffer + 1) + 1) * sizeof(char)); // Use um ponteiro temporário
                if (*(char *)(pBuffer+1000) == NULL) {
                    free(pAgenda); // Libere a memória alocada
                    return 0;
                }
                pAgenda = *(char *)(pBuffer+1000); // Atualize pAgenda com o ponteiro retornado por realloc
                *(char *)pBuffer = getchar();
            }
            *(char *)(pAgenda+*(int *)(pBuffer+1)) = '!';

            realloc(pBuffer, sizeof(pBuffer) + 4);
            if(pBuffer == NULL) return 0;
            *(int *)(pBuffer+1) = *(int *)(pBuffer+1) + 1;

            *(int *)(pBuffer+29) =  *(int *)(pBuffer+1); // armazena o tam do nome + email PS: tem que adaptar pra quando for ler mais de uma pessoa!
            
            printf("Digite a idade: ");
            scanf("%d",(int *)(pAgenda+*(int *)(pBuffer+29)));
            
            *(int *)(pBuffer+13) = *(int *)(pBuffer+13) + *(int *)(pBuffer+29) + 4; // atualiza o total de bytes ocupados

            *(int *)(pBuffer+9) = *(int *)(pBuffer+9) + 1; // aumenta o numero de pessoas armazenadas
        }

        // Remover pessoa:
        if(*(int *)(pBuffer+5) == 2){
            
        }

        // Buscar pessoa:
        if(*(int *)(pBuffer+5) == 3){
            
        }

        // Listar pessoas:
        if(*(int *)(pBuffer+5) == 4){
            printf("\nNome: ");
            for(*(int *)(pBuffer+17) = 0; *(int *)(pBuffer+17) < *(int *)(pBuffer+29); *(int *)(pBuffer+17) = *(int *)(pBuffer+17) + 1){
                if(*(char *)(pAgenda+*(int *)(pBuffer+17)) == '&'){
                    printf("\nEmail: ");
                }else if(*(char *)(pAgenda+*(int *)(pBuffer+17)) == '!'){
                    // terminou de printar o email
                }else{
                printf("%c", *(char *)(pAgenda+*(int *)(pBuffer+17)));
                }  
            }
            printf("\nIdade: %d\n",*(int *)(pAgenda+*(int *)(pBuffer+29)));
        }

        /*for(*(int *)(pBuffer+5) = 0; *(int *)(pBuffer+5) < *(int *)(pBuffer+1); *(int *)(pBuffer+5) = *(int *)(pBuffer+5) + 1){
            printf("%c", *(char *)(pAgenda+*(int *)(pBuffer+5)));
        }*/

        // Sair:
        if(*(int *)(pBuffer+5) == 5){
            printf("Agenda encerrada.");
            free(pAgenda);
            free(pBuffer);
            return 0;
        }
    }
    return 0;
}
