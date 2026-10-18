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

    void fill(vector<int>& v, TreeNode* root, int level){
        if(root == nullptr) return;
        v[level] = root->val;
        fill(v, root->left, level + 1);
        fill(v, root->right, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result(maxDepth(root), 0);
        fill(result, root, 0);
        return result;
    }
};
