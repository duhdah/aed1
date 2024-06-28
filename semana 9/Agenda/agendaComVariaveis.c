#include <stdio.h>
#include <stdlib.h>

// Versão do código usando a alocação de variáveis pra primeiro fazer a agenda funcionar, depois pensar em adaptar pra ponteiro do tipo void!


// OBS: tem que adaptar pra lista duplamente ligada!    
// Ao incluir pessoa, tem que usar fila ordenada pra deixar em ordem alfabetica
// Essas implementações vou fazer depois de fazer o código base pra não dar nó na cabeça :)

typedef struct{
    char nome[20];
    int idade;
    char email[20];
}Pessoa;

int menu(Pessoa **agenda, int *n);
void lerString(char *s);

int main(){
    Pessoa *agenda;
    int nPessoas = 0;
    int continua = 1;
    do{
        continua = menu(&agenda,&nPessoas);
    }while(continua);
    free(agenda);
    return 0;
}

int menu(Pessoa **agenda, int *n){
    printf("Digite a opcao que deseja:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nOpcao: ");
    int entrada = 0;
    do{
        scanf("%d",&entrada);
    }while(entrada<1||entrada>5);
    switch(entrada){
        case 1:
        printf("n: %d", *n);
            if(*n == 0) *agenda = (Pessoa *)malloc(sizeof(Pessoa));
            else{
                realloc(agenda,(*n + 1)*sizeof(Pessoa));
            }
            printf("Digite o nome da pessoa a ser adicionada: ");
            lerString((*agenda)[*n].nome);
            printf("Digite a idade da pessoa a ser adicionada: ");
            scanf("%d",&(*agenda)[*n].idade);
            printf("Digite o email da pessoa a ser adicionada: ");
            lerString((*agenda)[*n].email);
            *n = *n + 1;
            return 1;
        case 2:
            printf("Removendo pessoa...");
            // CONITNUAR
            return 1;
        case 3:
            printf("Buscando pessoa...");
            // CONTINUAR
            return 1;
        case 4:
            if(*n == 0) printf("Lista vazia.");
            else{
                for(int i = 0; i < *n; i++){
                    printf("//////// Pessoa %d ////////",i);
                    printf("Nome: %s",(*agenda)[i].nome);
                    printf("Idade: %d",(*agenda)[i].idade);
                    printf("Email: %s",(*agenda)[i].email);
                }
            }
            return 1;
        case 5:
            printf("O programa finalizou.");
            return 0;
        default:
            printf("Erro! Saindo do programa.");
            return 0;
    }
}

void lerString(char *s){
    getchar();
    fgets(s,20,stdin);
    s[strcspn(s,"\n")] = '\0';
}