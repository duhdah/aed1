#include <stdio.h>
#include <stdlib.h>

/*
83. Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
*/

/*
Funcionou (6 ms)
OBS: Fiz o meu codigo pensando em uma lista com cabeça, mas o LeetCode pedia sem.
Função para a lista sem cabeça.
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *atual = head;
    while (atual != NULL && atual->next != NULL) {
        if (atual->val == atual->next->val) {
            struct ListNode *d = atual->next;
            atual->next = atual->next->next;
            free(d);
        } else {
            atual = atual->next;
        }
    }
    return head;
} 
*/

struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* cria();
struct ListNode* deleteDuplicates(struct ListNode* head);
void imprimir(struct ListNode *head);
void adicionar(struct ListNode *head, int n);

int main(){

    struct ListNode* lista;
    lista = cria();
    int a=0, n;
    while(a!=4){
        printf("Selecione uma opcao:\n");
        printf("1. Imprimir a lista\n");
        printf("2. Adicionar numero\n");
        printf("3. Remover duplicados\n");
        printf("4. Sair\n");
        scanf("%d",&a);
        switch(a){
        case 1:
            imprimir(lista);
            break;
        case 2:
            printf("Digite o numero a ser adicionado na lista: ");
            scanf("%d",&n);
            adicionar(lista, n);
            break;
        case 3:
            deleteDuplicates(lista);
            break;
        case 4:
            break;
        }
    }
    return 0;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *atual = head->next;
    while (atual != NULL && atual->next != NULL) {
        if (atual->val == atual->next->val) {
            struct ListNode *d = atual->next;
            atual->next = atual->next->next;
            free(d);
        } else {
            atual = atual->next;
        }
    }
    return head->next;
} 

void imprimir(struct ListNode *head){
    if(head->next == NULL){
        printf("A lista esta vazia.");
    }else{
        struct ListNode *p;
        for(p = head->next; p!=NULL; p=p->next){
            printf("%d ",p->val);
        }
    }
}

void adicionar(struct ListNode *head, int n){
    struct ListNode *cel,*p;
    cel = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(cel == NULL){
        return;
    }
    cel->val = n;
    cel->next = NULL;
    p = head;
    while(p->next != NULL) p=p->next;
    p->next = cel;
}

/*
void inserefim(int n, celula *c){
    celula *final,*nova;
    nova = (celula *)malloc(sizeof(celula));
    for(final = c; final->prox!=NULL; final = final->prox);
    nova->conteudo = n;
    nova->prox = final->prox;
    final->prox = nova;
}
*/

struct ListNode* cria(){
    struct ListNode* listaNova;
    listaNova = (struct ListNode *)malloc(sizeof(struct ListNode));
    listaNova->next = NULL;
    return listaNova;
}