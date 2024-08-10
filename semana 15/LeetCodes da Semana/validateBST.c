/*
98. Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Link: https://leetcode.com/problems/validate-binary-search-tree/description/

Dificuldade: Médio
*/

// Funcionou (10 ms)

// os valores min e max servem pra verificar ao longo de toda arvore, nao só os imediatos, se os valores estão corretos
bool PercorreArvore(struct TreeNode *root, long min, long max) {
    if (root == NULL) return true;
    if (root->val <= min || root->val >= max) return false;
    return PercorreArvore(root->left, min, root->val) && PercorreArvore(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return PercorreArvore(root, LONG_MIN, LONG_MAX);
    // min e max são inicalizados como o menor e o maior valor que um long pode ter   
}
