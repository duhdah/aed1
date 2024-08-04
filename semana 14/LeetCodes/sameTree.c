/*
100. Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Dificuldade: Facil

Link: https://leetcode.com/problems/same-tree/description/
*/

// Funcionou (4 ms)
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true; 
    // se as duas forem NULL, são iguais
    
    if (p == NULL || q == NULL) return false; 
    // se só uma for NULL, são diferentes

    if (p->val != q->val) return false; 
    // se o valor delas for diferente, não é a mesma árvore

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // recursiva: chama a mesma função, verificando pros dois lados.
    // vai retornar true quando elas forem null (iguais) ou false  quando encontrar uma diferença entre elas
}