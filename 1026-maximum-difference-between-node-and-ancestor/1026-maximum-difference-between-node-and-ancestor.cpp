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
    
    int diff=0;
    void dfs(TreeNode *root, int maxi, int mini)
    {
        if(root==NULL)
            return;
        
        diff= max(diff, max(abs(maxi- root->val), abs(mini-root->val)));
        mini= min(mini, root->val);
        maxi= max(maxi, root->val);
        dfs(root->left, maxi, mini);
        dfs(root->right, maxi, mini);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int maxi= root->val;
        int mini= root->val;
        dfs(root, maxi, mini);
        
        return diff;
    }
};