#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Esse é um código auxiliar onde faço a agenda com variáveis, seguindo as regras de adicionar em ordem alfabética
e de usar lista duplamente encadeada.

Achei que seria mais fácil para entender como aplicar para depois partir para o pBuffer com o mesmo intuito.

 */

typedef struct pessoa{
    char nome[20];
    char email[20];
    int idade;
}Pessoa;

typedef struct nodo{
    Pessoa pessoa;
    struct nodo *prox;
    struct nodo *ant;
}Nodo;

void adicionaPessoa(Nodo **agenda, Pessoa p);
void removePessoa(Nodo **agenda, char *s);
Nodo *buscaPessoa(Nodo *agenda, char *s);
void listaPessoas(Nodo *agenda);
void limparAgenda(Nodo *agenda);

int main(){
    Nodo *agenda = NULL;
    int escolha = 0;
    while(escolha != 5){
        printf("Digite o que deseja fazer:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEscolha: ");
        scanf("%d",&escolha);
        getchar();
        if(escolha == 1){
            Pessoa p;
            printf("Digite o nome da pessoa: ");
            scanf("%[^\n]", p.nome);
            printf("Digite o email da pessoa: ");
            scanf("%s", p.email);
            printf("Digite a idade da pessoa: ");
            scanf("%d", &p.idade);
            adicionaPessoa(&agenda, p);
        }
        if(escolha == 2){
            char nome [20];
            printf("Digite o nome da pessoa a ser removida: ");
            scanf("%[^\n]", nome);
            removePessoa(&agenda,nome);
        }
        if(escolha == 3){
            char nome [20];
            printf("Digite o nome da pessoa a ser buscada: ");
            scanf("%[^\n]", nome);
            Nodo *p = buscaPessoa (agenda, nome);
            if(p != NULL){
                printf("\nNome: %s\n",p->pessoa.nome);
                printf("Email: %s\n",p->pessoa.email);
                printf("Idade: %d\n\n",p->pessoa.idade);
            }
        }
        if(escolha == 4){
            listaPessoas(agenda);
        }
        if(escolha == 5){
            printf("Fim do codigo.");
            limparAgenda(agenda);
            free(agenda);
            return 0;
        }
    }
}

void adicionaPessoa(Nodo **agenda, Pessoa p){
    Nodo *novaPessoa = (Nodo *)malloc(sizeof(Nodo));
    novaPessoa->pessoa = p;
    novaPessoa->prox = NULL;
    novaPessoa->ant = NULL;
    if (*agenda == NULL || strcmp((*agenda)->pessoa.nome, novaPessoa->pessoa.nome) > 0) {
        novaPessoa->prox = *agenda;
        if (*agenda != NULL) {
            (*agenda)->ant = novaPessoa;
        }
        *agenda = novaPessoa;
    }else{
        Nodo *ponteiro = *agenda;
        while((ponteiro->prox!=NULL) && (strcmp(ponteiro->prox->pessoa.nome,novaPessoa->pessoa.nome) < 0)){
            ponteiro=ponteiro->prox;
        }
        novaPessoa->prox = ponteiro->prox;
        novaPessoa->ant = ponteiro;
        ponteiro->prox = novaPessoa;
    }
}

void removePessoa(Nodo **agenda, char *s){
    if(agenda == NULL) printf("A agenda esta vazia.\n");
    else{
        Nodo *removido = buscaPessoa(*agenda,s);
        if(removido != NULL){
            if(removido->ant != NULL){
                removido->ant->prox = removido->prox;
            } else {
                *agenda = removido->prox;
            }
            if(removido->prox != NULL){
                removido->prox->ant = removido->ant;
            }
            free(removido);
        }
    }
}

Nodo *buscaPessoa(Nodo *agenda, char *s){
    if(agenda == NULL){
        printf("A agenda esta vazia.\n");
        return NULL;
    }
    Nodo *ponteiro = agenda;
    while((ponteiro!=NULL)&&(strcmp(ponteiro->pessoa.nome,s) != 0)){
        ponteiro=ponteiro->prox;
    }
    if(ponteiro == NULL){
        printf("Pessoa nao encontrada.\n");
        return NULL;
    }
    return ponteiro;
}

void listaPessoas(Nodo *agenda){
    if(agenda == NULL) printf("A agenda esta vazia.\n");
    else{
        Nodo *ponteiro = agenda;
        while(ponteiro!=NULL){
            printf("\nNome: %s\n",ponteiro->pessoa.nome);
            printf("Email: %s\n",ponteiro->pessoa.email);
            printf("Idade: %d\n\n",ponteiro->pessoa.idade);
            ponteiro=ponteiro->prox;
        }
    }
}

void limparAgenda(Nodo *agenda){
    Nodo *ponteiro = agenda;
    while(ponteiro != NULL){
        Nodo *temp = ponteiro;
        ponteiro = ponteiro->prox;
        free(temp);
    }
}