/*
145. Binary Tree Postorder Traversal

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Dificuldade: Fácil

Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
*/

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

void posOrdem(int *array, struct TreeNode* root, int *a){
    if(root == NULL){
        return;
    }
    if(root->left) posOrdem(array,root->left,a);
    if(root->right) posOrdem(array,root->right,a);
    array[(*a)++] = root->val;
    return;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *array = (int *)malloc(sizeof(int)*100), a = 0;
    posOrdem(array, root, &a);
    *returnSize = a;
    return array;
}