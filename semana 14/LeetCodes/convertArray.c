/*
108. Convert Sorted Array to Binary Search Tree

Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Dificuldade: Fácil

Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
*/

// Funcionou (2 ms)

struct TreeNode *arvore(int *nums, int inicio, int fim){
    if(inicio > fim) return NULL;
    int meio = (inicio+fim)/2;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[meio]; // o valor do meio como raiz para que metade dos valores estejam a direita e metade a esquerda
    
    root->left = arvore(nums,inicio,meio-1);
    root->right = arvore(nums,meio+1,fim);

    return root;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode *root = arvore(nums,0,numsSize-1);
    return root;
}