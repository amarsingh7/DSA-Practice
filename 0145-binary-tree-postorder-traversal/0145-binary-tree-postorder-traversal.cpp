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
private:
    void bfs(TreeNode* root, vector<int> &v)
    {
        if(root== NULL)
            return;
        bfs(root->left, v);
        bfs(root->right, v);
        v.emplace_back(root->val);
        
    }
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
         bfs(root, v);
        return v;
    }
};