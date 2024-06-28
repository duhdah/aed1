#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Funções básicas de PILHAS:

/*
RESET: Inicia a ED
PUSH: Insere um elemento (Precisa ter espaço)
POP: Remove um elemento (Não pode estar vazia)
EMPTY: Testa se tá vazia
CLEAR: Apaga todos os elementos
*/

// Pilha de alunos:

#define MAX 5

typedef struct{
    int ra;
    char nome[50];
}Aluno;

typedef struct{
    Aluno alunos[MAX];    
    int topo;
    int base;
    int limite;
}Pilha;

void Reset(Pilha *p);
bool Empty(Pilha *p);
bool Full(Pilha *p);
bool Push(Pilha *p, Aluno *a);
void Pop(Pilha *p, Aluno *a);
void Listar(Pilha *p);

int main(){
    Pilha p;
    Aluno a;
    Reset(&p);
    int entrada = 0;
    while(entrada != 4){
        printf("Digite a sua escolha:\n1) Adicionar aluno\n2) Remover aluno\n 3) Listar alunos\n4) Sair");
        scanf("%d",&entrada);
        getchar();
        if(entrada == 1){
            printf("Digite o nome do aluno a ser adicionado: ");
            fgets(a.nome, 50, stdin);
            a.nome[strcspn(a.nome,"\n")] = '\0';
            printf("Digite o RA do aluno a ser adicionado: ");
            scanf("%d",&a.ra);
            Push(&p,&a);
        }
        if(entrada == 2){
            Pop(&p,&a);
        }
        if(entrada == 3){
            Listar(&p);
        }
        if(entrada == 4){
            return 0;
        }
    }
}

void Reset(Pilha *p){
    p->base = 0;
    p->topo = 0;
    p->limite = MAX;
}

bool Empty(Pilha *p){
    return p->topo == 0;
}

bool Full(Pilha *p){
    return p->topo == MAX;
}

bool Push(Pilha *p, Aluno *a){
    if(!Full(p)){
        p->alunos[p->topo] = *a;
        p->topo++;
        printf("Aluno adicionado!\n");
        return true;
    }else{
        printf("Lista cheia!\n");
        return false;
    }
}

void Pop(Pilha *p, Aluno *a){
    if(Empty(p)) return;
    p->topo--;
    *a = p->alunos[p->topo];
}

// Versao do listar que só percorre a lista do fim ao começo imprimindo:
void Listar(Pilha *p){
    if(Empty(p)) return;
    for(int i = p->topo - 1; i >= p->base; i--){
        printf("Aluno %d: %s\n",i,p->alunos[i].nome);
    }
}


/*
Esse metodo apaga a lista ao imprimir:
void Listar(Pilha *pilha){
    printf("Listando... ");
    while(!Empty(pilha)){
        Aluno aluno;
        Pop(pilha,&aluno);
        printf("%i - %s",aluno.ra, aluno.nome);
    }
}
*/

/*
Esse metodo nao apaga a lista, ele copia a lista para uma nova e da pop nela!
void Listar(Pilha *pilha){
    printf("Listando... ");
    Pilha novaPilha;
    novaPilha = *pilha;
    while(!Empty(&novaPilha)){
        Aluno aluno;
        Pop(&novaPilha,&aluno);
        printf("%i - %s",aluno.ra, aluno.nome);
    }
}
*/