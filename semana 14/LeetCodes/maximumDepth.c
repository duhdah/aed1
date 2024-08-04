/*
104. Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Dificuldade: Fácil

Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
*/

// Funcionou (6 ms)

 int Altura(struct TreeNode *p){
    int esq, dir;
    if(p == NULL){
        return 0;
    }
    esq = Altura(p->left);
    dir = Altura(p->right);
    if(esq > dir) return esq + 1;
    else return dir + 1;
}

int maxDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    return Altura(root);
}

