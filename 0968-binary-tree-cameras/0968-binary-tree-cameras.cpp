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
    
    string solve(TreeNode* root, int &ans)
    {
        if(root==NULL)
            return "no-need-camera";
        string l= solve(root->left, ans);
        string r= solve(root->right, ans);
        
        if(l=="cover-me" || r=="cover-me")
        {
            ans++;
            return "have-camera";
        }
        else if(l=="have-camera" || r=="have-camera")
            return "no-need-camera";
           
        return "cover-me";
    }
    
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(solve(root, ans)=="cover-me")
            ans++;
        
        return ans;
    }
};