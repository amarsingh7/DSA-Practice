class Solution {
public:
    int i = 0; // Index to keep track of the position in the input string

    TreeNode* solve(string &temp, int index) {
        // Base case: If the current index exceeds the string length, return NULL
        if (index >= temp.size())
            return NULL;

        string ans = "";
        int x = 0;
        int st = i; // Start position for backtracking

        // Count the number of hyphens to determine the level
        while (temp[i] == '-')
            i++, x++;

        // If the number of hyphens doesn't match the expected level, backtrack and return NULL
        if (x != index) {
            i = st; // Backtrack the index
            return NULL;
        }

        // Extract the node value
        while (temp[i] != '-' && i < temp.size()) {
            ans += temp[i];
            i++;
        }

        int val = stoi(ans);

        // Create a new TreeNode with the extracted value
        TreeNode* res = new TreeNode(val);

        // Recursively build the left and right subtrees
        res->left = solve(temp, index + 1);
        res->right = solve(temp, index + 1);

        return res;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        // Call the solve function to construct the binary tree
        return solve(traversal, 0);
    }
};