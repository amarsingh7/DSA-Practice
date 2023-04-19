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
    
    vector<int> dfs(TreeNode *root)
    {
        if(!root)
            return {-1, -1, -1};
        vector<int> lft= dfs(root->left);
        vector<int> rgt= dfs(root->right);
        int result;
        result= max(max(lft[1], rgt[0])+1, max(lft[2], rgt[2]));
        
        return {lft[1]+1, rgt[0]+1, result};
            
    }
    int longestZigZag(TreeNode* root) {
        return dfs(root)[2];
    }
};