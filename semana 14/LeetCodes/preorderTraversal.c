/*
144. Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Dificuldade: Fácil

Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

// Funcionou (4 ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void preOrdem(int *array, struct TreeNode* root, int *a){
    if(root == NULL){
        return;
    }
    array[(*a)++] = root->val;
    if(root->left) preOrdem(array,root->left,a); // obs: 'a' é int *, por isso, não precisa do &
    if(root->right) preOrdem(array,root->right,a); // obs: 'a' é int *, por isso, não precisa do &
    return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
        *returnSize = 0;
        int *array = (int *)malloc(sizeof(int)*100), a = 0; 
        preOrdem(array, root, &a); // obs: 'a' é int, por isso, chama com &
        *returnSize = a;
        return array;
}