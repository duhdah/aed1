/*
101. Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Dificuldade: Fácil

Link: https://leetcode.com/problems/symmetric-tree/description/
*/

// Funcionou (0 ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool simetrica(struct TreeNode *left, struct TreeNode *right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    return (left->val == right->val) && simetrica(left->left, right->right) && simetrica(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL) return true;
    return simetrica(root->left, root->right);
}