#include <stdio.h>

/*

    ESTRUTURAS DE DADOS: Regras para armazenamento e acesso a informações.
    - São usados mecanismos de abstração para simplificar o acesso do usuário. (Tipos abstratos de dados)
    - Têm interfaces, como um interruptor ou um carro.

    Exemplo: Lavar pratos. Sempre coloca em cima e remove de cima (Pilha!)
    - As alterações em textos são feitas em pilha (botão undo).
    - São desfeitas em ordem, da ultima a ter sido feita até a primeira.

    Uma pilha é uma LIFO (Last In, First Out).
    - Não precisa ser um vetor. Será uma pilha se seguirmos as regras da LIFO.
    - Parâmetros de uma pilha: Base, topo e limite.
    - As operações devem sincronizar com as variáveis referentes a pilha.

    Pré-condições para operações de pilhas:
    - PUSH: A pilha deve ter espaço disponível para a inserção de novos elementos.
    - POP: A pilha não pode estar vazia.

*/

// Pilha estática:

const int MAX = 10;
// Estatica: limite da pilha é fixo.

typedef struct Aluno{
    int ra;
    char nome[50];
};

typedef struct Pilha{
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
};

// Função reset da pilha:

void Reset (Pilha *pilha){
    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

// Função para verificar se a lista está vazia:

bool Empty (Pilha *pilha){
    return pilha->topo == 0;
}

// Função para verificar se a lista está cheia:

bool Full (Pilha *pilha){
    return pilha->topo == MAX;
}

// Função para colocar um item na pilha:

bool PUSH (Pilha *pilha, Aluno *item){
    if(!Full(pilha)){
        pilha->alunos[pilha->topo] = *item;
        pilha->topo++;
        return true;
    }else{
        return false;
    }
}

// Função para tirar elemento da pilha:

void POP (Pilha *pilha, Aluno *aluno){
    if(pilha->topo == 0) return;
    pilha->topo--;
    *aluno = pilha->alunos[pilha->topo];
}

// Função para listar elementos de uma lista:
void Listar (Pilha *pilha){
    printf("\nListando...\n");
    while(!Empty(pilha)){
        Aluno aluno;
        POP(pilha,&aluno);
        printf("\n%i - %s",aluno->ra,aluno->nome);
    }
}