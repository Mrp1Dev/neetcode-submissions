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

    void fill(vector<vector<int>>& v, TreeNode* root, int level){
        if(root == nullptr) return;
        v[level].push_back(root->val);
    
        
        fill(v, root->left, level+1);
        fill(v, root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int d = maxDepth(root);
        for(int i =0; i < d; i++)
            result.push_back(vector<int>());
        fill(result, root, 0);
        return result;
    }
};
