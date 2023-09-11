class Solution {
public:
    vector<vector<vector<int>>> dp;  
    
    int solve(int r1, int c1, int c2, vector<vector<int>>& grid) {
        int n = grid.size();
        int r2 = r1 + c1 - c2; 
        // Calculate the second robot's row
        
        // Base case: Check if out of bounds or obstacle
        if (r1 == n || r2 == n || c1 == n || c2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -999999;  
        } 
        else if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1]; 
            // Reached the bottom-right cell, return its value
        } 
        else if (dp[r1][c1][c2] != INT_MIN) {
            return dp[r1][c1][c2]; 
            // If result is already computed, return it
        } 
        else {
            int ans = grid[r1][c1]; 
            // Cherries collected at the current cell
            
            // If the two robots are not in the same column, add cherries from both cells
            if (c1 != c2) 
                ans += grid[r2][c2];
            
            // Recursively calculate the maximum cherries picked by exploring all valid moves
            ans += max(max(solve(r1, c1 + 1, c2 + 1, grid), solve(r1 + 1, c1, c2 + 1, grid)),
                       max(solve(r1, c1 + 1, c2, grid), solve(r1 + 1, c1, c2, grid)));
            
            dp[r1][c1][c2] = ans; 
            return ans;
        }
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, INT_MIN))); 
        
        int result = solve(0, 0, 0, grid); 
        // Start the recursive search from the top-left corner
        return max(0, result); 
    }
};
