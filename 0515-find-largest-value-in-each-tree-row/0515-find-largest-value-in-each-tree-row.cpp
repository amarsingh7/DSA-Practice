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
    void solve(TreeNode* root, vector<vector<int>> &temp, int level)
    {
        if(root==NULL)
            return;
        if(level==temp.size())
            temp.push_back({})    ;
        temp[level].push_back(root->val);
        solve(root->left, temp, level+1);
        solve(root->right, temp, level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        
        vector<vector<int>> temp;
        solve(root, temp, 0);
        
        for(auto x:temp)
            ans.push_back(*max_element(x.begin(), x.end()));
        
        return ans;
    }
};