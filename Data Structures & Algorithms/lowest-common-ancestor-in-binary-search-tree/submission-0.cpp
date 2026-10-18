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
    bool contains(TreeNode* root, TreeNode* node){
        if(root == nullptr) return false;
        if(root == node) return true;
        return contains(root->left, node) || contains(root->right, node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(contains(root->left, p) && contains(root->left, q))
            return lowestCommonAncestor(root->left, p, q);
        if(contains(root->right, p) && contains(root->right, q))
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};
