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
    
    pair<int, int> res(TreeNode* root)
    {
        if(root==NULL)
            return {0, 0};
        pair<int, int> l=  res(root->left);
        pair<int, int> r=  res(root->right);
        return {max(root->val + l.second +r.second, l.first +r.first), l.first +r.first};
            
    }
    int rob(TreeNode* root) {
        
        return res(root).first;
    }
};