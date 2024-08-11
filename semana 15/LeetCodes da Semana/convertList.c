/*
109. Convert Sorted List to Binary Search Tree

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

Dificuldade: Médio
*/

// Funcionou (21 ms)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
// aproveitei a função que tinha feito em um exercicio semelhante que converte um array em uma arvore e transformei a lista em array pra usar
struct TreeNode *arvore(int *nums, int inicio, int fim){
    if(inicio > fim) return NULL;
    int meio = (inicio+fim)/2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[meio]; // o valor do meio como raiz para que metade dos valores estejam a direita e metade a esquerda
    root->left = arvore(nums,inicio,meio-1);
    root->right = arvore(nums,meio+1,fim);
    return root;

}

// transforma a lista em array e depois transforma o array em arvore
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int *array = (int*)malloc(sizeof(int)*10000), index = 0, tam = 0;
    struct TreeNode *tree = NULL;
    struct ListNode *p;
    for(p = head; p != NULL; p=p->next){
        tam++;
    }
    if(tam == 0) return tree;
    array = (int*)malloc(sizeof(int)*tam), index = 0;
    for(p = head; p != NULL; p=p->next){
        array[index++] = p->val;
    }
    tree = arvore(array, 0, index-1);
    return tree;
}
