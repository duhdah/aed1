#include <stdio.h>

// AULA GRAVADA SOBRE FILAS:

/*
Assim como as pilhas, as filas são estruturas de dados restritas.

Comportamento das filas:
->  Inclusão numa extremidade;
->  Remoção na outra extremidade.

FIFO: First In, First Out
O primeiro que entra é o primeiro que sai.

*/

// Estruturas:

typedef struct{
    int cod;
    char nome[40];
    float preco;
}SProduto;
// Representa o elemento ou dado armazenado na fila.

typedef struct{
    SProduto info;
    struct STipoFila *pNext;
}STipoFila;
// Representa um nodo da fila.

typedef struct{
    STipoFila *pFirst;
    STipoFila *pLast;
}SFila;
// Representa a fila, armazena o seu início e o seu fim.

// Encapsulamento: Não misturar a informação em si com o modo como ela é lidada no código.

// Ao criar uma fila, tanto *pFirst quanto *pLast devem apontar para NULL (Fila vazia).
// Primeiro elemento (PUSH) precisa atualizar os dois ponteiros.
// Quando mais um for adicionado, o First permanece e o Last precisa mudar.
// Para cuidar dessas situações, devemos usar ifs.

// Na hora de excluir com o POP, o que acontece com o primeiro nodo?
// Se dermos free nele, o pFirst continuara apontando para o lixo de memoria.

// Função RESET:

SFila *RESET(SFila *pOldFila){

    if(pOldFila)
        Clear(pOldFila);

    SFila *pFila;
    pFila = (SFila *)malloc(sizeof(SFila));
    pFila->pFirst = NLL;
    pFila->pLast = NULL;

    return pFila;

}

// Função PUSH:

void PUSH(SFila *pFila, SProduto *pProd){

    STipoFila *pNovo;
    pNovo = (STipoFila *)malloc(sizeof(STipoFila));
    pNovo->info = *pProd;
    pNovo->pNext = NULL;

    if(pFila->pLast != NULL){
        pFila->pLast->pNext = pNovo;
    }else
        pFila->pFirst = pNovo;

    pFila->pLast = pNovo;
}

// Função POP:

int POP(SFila *pFila, SProduto *pProd){
    STipoFila *pNodo;

    if(pFila->pFirst == NULL){
        puts("FilaVazia!");
        return 0;
    }else{
        pNodo = pFila->pFirst;
        *pProd = pFila->pFirst->info;
        pFila->pFirst = pFila->pFirst->pNext;
    
        if(pFila->pFirst == NULL){
            pFila->pLast = NULL;
        }

        free(pNodo);
        return 1;
    }

}

void imprimeFila(SFila *pFila){
    STipoFila *pNodo;
    if(pFila->pFirst == NULL)
        puts("FilaVazia!");
    else
        for(pNodo = pFila->pFirst; pNodo!=NULL; pNodo->pNext){
            prtntf("Nome: %s Cod: %d Preco %3.2f\n",pNodo->info.nome,pNodo->info.cod,pNodo->info.preco);
        }
}

// Estrutura de Dados Lista Ligada:

struct lista{
    SNodo *pFirst;
}
typedef struct lista SLista;

struct nodo{
    Sinfo Dado;
    struct nodo *pNext;
}
typedef struct nodo SNodo;

struct info{
    int info;
}
typedef struct info SInfo;

/* 

Fila com inclusao (PUSH) por ordem de prioridade (ex.: banco):

    A exclusão (POP) continua sendo numa ponta só, a posição do PUSH depende da prioridade. 
    O numero de prioridade não diz a posição que ele vai ficar, mas sim deve ser comparado com quem já está na fila.

*/