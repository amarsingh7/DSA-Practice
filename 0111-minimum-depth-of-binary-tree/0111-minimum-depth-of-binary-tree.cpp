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
    int minDepth(TreeNode* root) {
        TreeNode* left;
        TreeNode* right;
        if(root==NULL)
            return 0;
        
        int countl;
        int countr;
        
        countl= minDepth(root->left);
        countr= minDepth(root->right);
        
        return 1 + (min(countl, countr) ? min(countl, countr) : max(countl, countr));
        
        
    }
};