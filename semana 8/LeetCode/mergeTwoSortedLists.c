/*
    21. Merge Two Sorted Lists

    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
    Return the head of the merged linked list.
    
    Link: https://leetcode.com/problems/merge-two-sorted-lists/description/

*/

// Funcionou (5 ms, 5.84 MB)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode *inicio, *p;
    inicio = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = inicio;

    for (; list1 != NULL && list2 != NULL; p = p->next) {
        if (list1->val <= list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
    }
    if(list1 != NULL){
        p->next = list1;
    }else{
        p->next = list2;
    }

    return inicio->next;
}


// Se as listas não tivessem ordenadas:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    node *atual, *proxima, *lista2;

    for(atual = list1; atual != NULL; atual = atual->next){
        for(proxima = atual->next; proxima != NULL; proxima = proxima -> next){
            if(atual->val > proxima->val){
                int temp = proxima->val;
                proxima->val = atual->val;
                atual->val = temp;
            }
        }
    }

    lista2 = list2;
    while (lista2 != NULL) {
        node *celula = (node *)malloc(sizeof(node));
        celula->val = lista2->val;
        celula->next = NULL;
        node *anterior = NULL;
        atual = list1;
        while (atual != NULL && atual->val < celula->val) {
            anterior = atual;
            atual = atual->next;
        }
        if (anterior == NULL) {
            celula->next = list1;
            list1 = celula;
        } else {
            anterior->next = celula;
            celula->next = atual;
        }
        lista2 = lista2->next;
    }
    return list1;
}