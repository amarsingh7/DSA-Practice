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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<double> res, temp;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            double ans=0;
            double cnt=0;
            int n= q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node= q.front();
                q.pop();
                temp.push_back(node->val) ;
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans= 1LL*(accumulate(temp.begin(), temp.end(), 0.0));
            cnt= 1LL*(temp.size());
            double fck= 1LL*(ans/cnt);
            res.push_back(fck);
            
            temp.clear();
            
        }
        return res;
    }
};