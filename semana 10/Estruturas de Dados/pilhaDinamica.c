#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int valor;
    struct Node *next;
}node;

node *Reset(void);
bool Empty(node *head);
bool Full(node *head);
bool Push(node *head, int elemento);
void Pop (node *head, int *valor);
void Listar (node *head);

int main(){
    node *pilha = Reset();
    int valor;
    Push(pilha, 10);
    Push(pilha, 9);
    Push(pilha, 7);
    Push(pilha, 5);
    Push(pilha, 2);
    Pop(pilha, &valor);
    Listar(pilha);

    while(!Empty(pilha)){
        Pop(pilha, &valor);
    }
    free(pilha);
    return 0;
}

bool Empty(node *head){
    return head->next == NULL;
}

node *Reset(void) {
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}

/*
Não fica mais cheia!
bool Full(node *head){
    return p->limite == p->topo;
}
*/

bool Push(node *head, int elemento){
    node *novo = (node *)malloc(sizeof(node));
    novo->valor = elemento;
    novo->next = head->next;
    head->next = novo;
    return true;
}

void Pop (node *head, int *valor){
    if(Empty(head)){
        printf("A pilha esta vazia!");
    }else{
        *valor = head->next->valor;
        node *temp;
        temp = head->next;
        head->next = temp->next;
        free(temp);
    }
}

void Listar (node *head){
    if(Empty(head)){
        printf("A lista esta vazia!");
    }else{
        node *auxiliar = Reset();
        int valor;
        printf("Elementos da pilha: ");
        while(!Empty(head)){
            Pop(head, &valor);
            printf("%d ", valor);
            Push(auxiliar,valor);
        }

        while(!Empty(auxiliar)){
            Pop(auxiliar, &valor);
            Push(head,valor);
        }
    }
}