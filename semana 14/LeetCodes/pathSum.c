/*
112. Path Sum

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Dificuldade: Fácil

Link: https://leetcode.com/problems/path-sum/description/
*/

// Funcionou (9 ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool ConfereCaminhos(struct TreeNode* root, int targetSum){
    if(root == NULL) return false;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL) {
        return targetSum == 0;
    }
    return ConfereCaminhos(root->left, targetSum) || ConfereCaminhos(root->right, targetSum);

}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    return ConfereCaminhos(root, targetSum);

}