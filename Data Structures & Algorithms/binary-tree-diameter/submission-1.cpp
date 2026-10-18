/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int diameter = maxDepth(root->left) + maxDepth(root->right);
        return max(diameter, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
};
