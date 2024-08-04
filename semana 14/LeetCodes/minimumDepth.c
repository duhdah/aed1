/*
111. Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Dificuldade: Fácil

Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
*/

// Funcionou (156 ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;;
}