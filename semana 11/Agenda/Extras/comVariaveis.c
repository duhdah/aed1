#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Exercicio da primeira semana: Lista de nomes

void adicionachar(char **lista, int *tamanhoLista, char c);
void removenome(char **lista, int *tamanhoLista, char *n, int t);

int main() {
    char *lista = NULL;
    int tamanhoLista = 0, entrada = 0;

    while (entrada != 4) {
        printf("1) Adicionar nome\n2) Remover nome\n3) Listar\n4) Sair\n");
        scanf("%d", &entrada);
        getchar();
            if (entrada == 1) {
                printf("Digite o nome a ser adicionado na lista: ");
                char c;
                while (((c = getchar()) != '\n') && (c != EOF)) {
                    adicionachar(&lista, &tamanhoLista, c);
                }
                if ((tamanhoLista > 0) && (lista[tamanhoLista - 1] != '&')) {
                    adicionachar(&lista, &tamanhoLista, '&');
                }
            }       
            else if (entrada == 2) {
            if (tamanhoLista == 0) {
                printf("Nao ha nenhum nome na lista.\n");
            } else {
                printf("Digite o nome a ser removido da lista: ");
                char *nomeRemovido = NULL;
                int nomeLen = 0;
                char c;
                while ((c = getchar()) != '\n' && c != EOF) {
                    adicionachar(&nomeRemovido, &nomeLen, c);
                }
                removenome(&lista, &tamanhoLista, nomeRemovido, nomeLen);
                free(nomeRemovido);
            }
        } else if (entrada == 3) {
            if(!tamanhoLista){
                printf("Nao ha nenhum nome na lista.\n");
            }else{
                printf("\nLista de nomes:\n");
                for (int i = 0; i < tamanhoLista; i++) {
                    if (lista[i] == '&') {
                        printf("\n");
                    } else {
                        printf("%c", lista[i]);
                    }
                }
                printf("\n");
            }
        } else if (entrada == 4) {
            break;
        } else {
            printf("Opcao invalida.\n");
        }
    }
    free(lista);
    return 0;
}

void adicionachar(char **lista, int *tamanhoLista, char c){
    char *p = realloc(*lista, (*tamanhoLista + 1) * sizeof(char));
    if (p == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }
    *lista = p;
    (*lista)[*tamanhoLista] = c;
    (*tamanhoLista)++;
}

void removenome(char **lista, int *tamanhoLista, char *n, int t){
    char *buffer = malloc((*tamanhoLista) * sizeof(char));
    if (!buffer) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }
    int tamBuffer = 0;
    int i = 0;
    int encontrou = 0;
    while (i < *tamanhoLista) {
        int j = i;
        while (j < *tamanhoLista && (*lista)[j] != '&') {
            j++;
        }

        int tamNome = j - i;
        if (tamNome == t && strncmp(*lista + i, n, t) == 0) {
            encontrou = 1;
        } else {
            if (tamBuffer > 0) {
                buffer[tamBuffer++] = '&';
            }
            memcpy(buffer + tamBuffer, *lista + i, tamNome);
            tamBuffer += tamNome;
        }
        i = j + 1;
    }
    if (tamBuffer > 0 && buffer[tamBuffer - 1] == '&') {
        tamBuffer--;
    }
    if (encontrou) {
        if (tamBuffer == 0) {
            free(*lista);
            *lista = NULL;
            *tamanhoLista = 0;
            printf("A lista agora esta vazia.\n");
        } else {
            *lista = realloc(*lista, tamBuffer + 1);
            if (!*lista) {
                printf("Falha ao realocar memoria");
                free(buffer);
                return;
            }
            memcpy(*lista, buffer, tamBuffer);
            (*lista)[tamBuffer] = '\0';
            *tamanhoLista = tamBuffer;
        }
    } else {
        printf("Nome nao encontrado na lista.\n");
    }
    free(buffer);
}


