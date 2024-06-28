
/*
234. Palindrome Linked List

Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Link: https://leetcode.com/problems/palindrome-linked-list/description/
*/

// Funcionou (227 ms)
// Deu certo, mas não foi muito eficiente
// Devo ter implementado a pilha de uma maneira diferente da esperada
// Vale a pena rever!


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct Stack{
    int metadeDaLista[50000];
    int topo;
};

bool isPalindrome(struct ListNode* head) {
    struct ListNode *ponteiro;
    struct Stack stack;
    stack.topo = 0;
    int tamanhoDaLista = 0;
    for(ponteiro = head; ponteiro!= NULL; ponteiro=ponteiro->next) tamanhoDaLista++;
    int metade = tamanhoDaLista/2;
    ponteiro = head;
    for(int i = 0; i < tamanhoDaLista; i++){
        if(i < metade){
            printf("Elemento no stack: %d\n",ponteiro->val);
            stack.metadeDaLista[stack.topo] = ponteiro->val; 
            stack.topo++; 
        }else if((i == metade) && (tamanhoDaLista % 2 == 1)){

        }else{
            printf("Conferindo com o stack: %d\n",ponteiro->val);
            stack.topo--;
            printf("Valor no stack: %d\n",stack.metadeDaLista[stack.topo]);
            printf("Valor da lista: %d\n",ponteiro->val);
            if(stack.metadeDaLista[stack.topo] != ponteiro->val) return false;
        }
        ponteiro=ponteiro->next;
    }
    return stack.topo == 0;
}
