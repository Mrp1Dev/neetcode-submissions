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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        //if(root->left == nullptr && root->right != nullptr)

        TreeNode* r = root->right;
        if(root->left != nullptr)
            root->right = invertTree(root->left);
        else 
            root->right = nullptr;
        if(r != nullptr)
            root->left = invertTree(r);
        else 
            root->left = nullptr;
        return root;
    }
};
