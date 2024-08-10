
/*
1382. Balance a Binary Search Tree

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Dificuldade: Médio

Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/
*/

// Funcionou (86 ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// estrategia:

//1. percorrer a arvore (inorder) para passar os valores em ordem crescente para uma array

void ArvoreParaArray(struct TreeNode *root, int *array, int *indice){
    if(root !=  NULL){
        ArvoreParaArray(root->left, array, indice);
        array[(*indice)++] = root->val;
        ArvoreParaArray(root->right, array, indice);
    }
}


//2. inserir os valores da array em uma nova arvore
struct TreeNode *ArvoreBalanceada(int *array, int inicio, int fim){
    if(inicio>fim) return NULL;
    int meio = (inicio+fim)/2;
    struct TreeNode *nodo = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    nodo->val = array[meio];
    nodo->left = ArvoreBalanceada(array, inicio, meio-1);
    nodo->right = ArvoreBalanceada(array, meio+1, fim);
    return nodo;
}

//3. return com a nova arvore 
struct TreeNode* balanceBST(struct TreeNode* root) {
    if(root == NULL) return NULL;
    int *array = (int *)malloc(10000*sizeof(int)), indice = 0;
    ArvoreParaArray(root,array,&indice);
    struct TreeNode *novaArvore = ArvoreBalanceada(array,0,indice-1);
    return novaArvore;
}