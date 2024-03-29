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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL)
            return result;

        queue <TreeNode *> q;
        q.push(root);

        bool leftToright = true;

        while(!q.empty())
        {
            int size = q.size();
            
            vector <int> ans(size);

            for(int i = 0 ; i < size ; i++)
            {
                TreeNode* qfront = q.front();
                q.pop();

                int index;
                if(leftToright)
                    index = i;
                
                else
                    index = size - i - 1;

                ans[index] = qfront->val;

                if(qfront->left)
                    q.push(qfront->left);
                
                if(qfront->right)
                    q.push(qfront->right);
            }
            leftToright = !leftToright;
            result.push_back(ans);
        }
        return result;
    }
};