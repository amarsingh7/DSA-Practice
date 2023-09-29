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
    
    vector<vector<int>> ans;
    void lt(TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        if(level==ans.size())
            ans.push_back({});
        ans[level].push_back(root->val);
        lt(root->left, level+1);
        lt(root->right, level+1);
            
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        lt(root, 0);
        int n= ans.size();
        vector<int> res(ans[n-1].begin(), ans[n-1].end());
        
        int sum= 0;
        for(auto x:res)
            sum+= x;
        
        return sum;
        
    }
};