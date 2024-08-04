/*
94. Binary Tree Inorder Traversal

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Dificuldade: Fácil

Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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

void percorrer(struct TreeNode *root, int *vetor, int *a) {
    if (root == NULL) return;
    if (root->left) percorrer(root->left, vetor, a);
    vetor[(*a)++] = root->val; // mesma lógica do imprimir (vai entre a linha que trata do left e do right)
    if (root->right) percorrer(root->right, vetor, a);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *vetor = (int *)malloc(100 * sizeof(int));
    if (root == NULL) return vetor;
    int a = 0;
    percorrer(root, vetor, &a);
    *returnSize = a;
    return vetor;
}