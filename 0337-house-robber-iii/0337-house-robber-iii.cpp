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
    // A pair of integers represents the result of robbing the current subtree:
    // First value: Maximum amount that can be robbed from the current subtree.
    // Second value: Maximum amount that can be robbed from the subtree without including the current node.
    pair<int, int> res(TreeNode* root) {
        if (root == NULL)
            return {0, 0}; 

        // Recursively calculate the results for the left and right subtrees.
        pair<int, int> l = res(root->left);
        pair<int, int> r = res(root->right);

        // Calculate the maximum amount that can be robbed from the current subtree.
        // Case 1: Rob the current node and skip the immediate children.
        // Case 2: Skip the current node and consider the maximum amounts from the left and right subtrees.
        int maxRobWithCurrent =  l.first+r.first;
        int maxRobWithoutCurrent = max(l.first+r.first, root->val + l.second + r.second);

        return {maxRobWithoutCurrent, maxRobWithCurrent};
    }

    int rob(TreeNode* root) {
        // Return the maximum amount that can be robbed from the root node's subtree.
        return res(root).first;
    }
};
