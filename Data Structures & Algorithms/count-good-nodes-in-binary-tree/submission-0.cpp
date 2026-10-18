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
    int maxDepth(TreeNode* root){
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    void fill(int& count, int maxSoFar, TreeNode* root){
        if(root==nullptr) return;
        if(maxSoFar <= root->val){
            count += 1;  
            maxSoFar = root->val;
        } 
        fill(count, maxSoFar, root->left);
        fill(count, maxSoFar, root->right);
    }
    int goodNodes(TreeNode* root) {
        int count = 0; 
        fill(count, -101, root);
        return count;
    }
};
