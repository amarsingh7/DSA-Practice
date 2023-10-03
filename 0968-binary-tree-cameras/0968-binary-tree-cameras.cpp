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
    // (no-need-camera, cover-me, have-camera)
    string solve(TreeNode* root, int &ans)
    {
        if(root==NULL)  // if root is null, so no camera needed
            return "no-need-camera";
        string l= solve(root->left, ans);
        string r= solve(root->right, ans);
        
        if(l=="cover-me" || r=="cover-me")
        {   // if both child is unsafe, give a camera to parent
            ans++;
            return "have-camera";
        }   
        // if a child have camera, mo need of camera on its parent.
        else if(l=="have-camera" || r=="have-camera")
            return "no-need-camera";
           
        return "cover-me";  // no one is protcecting root, so camera needed to root
    }
    
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(solve(root, ans)=="cover-me")
            ans++;
        
        return ans;
    }
};