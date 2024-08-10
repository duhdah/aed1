/*
235. Lowest Common Ancestor of a Binary Search Tree

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Dificuldade: Médio

Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
*/

// Funcionou (35 ms)

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if( root == NULL || root == p || root == q ) return root;

    struct TreeNode *left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) return root;
    if (left != NULL) return left;
    else return right;
}
