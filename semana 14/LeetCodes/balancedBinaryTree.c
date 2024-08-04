/*
110. Balanced Binary Tree

Given a binary tree, determine if it is height-balanced

Dificuldade: Fácil

Link: https://leetcode.com/problems/balanced-binary-tree/description/
*/

// Funcionou (7 ms)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// funções Altura e FB da AVL
int FB(struct TreeNode *node){
    if(node == NULL) return 0;
    return Altura(node->left) - Altura(node->right);
}

int Altura(struct TreeNode *node){
    if(node == NULL) return 0;
    int esq = Altura(node->left);
    int dir = Altura(node->right);
    if(esq>dir) return esq + 1;
    else return dir + 1;
}

// usa Altura para conferir a árvore inteira
bool ConfereArvore(struct TreeNode *root){
    if(root == NULL) return true;
    int esq = Altura(root->left);
    int dir = Altura(root->right);
    if((esq - dir < -1) || (esq - dir > 1)) return false;
    return ConfereArvore(root->left) && ConfereArvore(root->right);
}

bool isBalanced(struct TreeNode* root) {
    return ConfereArvore(root);
}