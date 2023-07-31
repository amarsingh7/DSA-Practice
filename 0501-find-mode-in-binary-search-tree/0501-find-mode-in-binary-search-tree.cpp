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
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        vector<int> res;
        unordered_map<int, int> ump;
        for(auto x:v)
            ump[x]++;
        int maxi=0;
        for(auto x:ump)
        {
            maxi= max(maxi, x.second);
        }
        for(auto x:ump)
        {
            if(x.second ==maxi)
                res.push_back(x.first);
        }
        return res;
            
    }
};