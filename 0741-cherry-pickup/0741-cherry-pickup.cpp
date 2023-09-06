class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int solve(int r1, int c1, int c2, vector<vector<int>>& grid)     {
        int n = grid.size();
        int r2 = r1 + c1 - c2;
        
        if (r1 == n || r2 == n || c1 == n || c2 == n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -999999;
        } 
        else if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        } 
        else if (dp[r1][c1][c2] != INT_MIN) {
            return dp[r1][c1][c2];
        } 
        else 
        {
            int ans = grid[r1][c1];
            if (c1 != c2) 
                ans += grid[r2][c2];
            
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
        return max(0, result); 
    }
};
