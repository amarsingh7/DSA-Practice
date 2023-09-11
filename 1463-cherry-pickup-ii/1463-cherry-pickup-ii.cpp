class Solution {
public:
    int dp[101][101][101];
    
    int solve(int r, int c1, int c2, vector<vector<int>> &grid) {
        int row = grid.size();
        int c= grid[0].size();
        
        if(r== row)
            return 0;
        if(dp[r][c1][c2] != -1)
            return dp[r][c1][c2];
        
        int res=0;
        for(int di= -1; di<=1; di++)
        {
            for(int dj= -1; dj<=1; dj++)
            {
                int x= c1+di;
                int y= c2+dj;
                
                if(x>=0 and y>x and y<c)
                    res= max(res, solve(r+1, x, y, grid));
            }
        }
        return dp[r][c1][c2]= grid[r][c1] + grid[r][c2]+ res;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid[0].size();
        int m= grid.size();
        
        memset(dp, -1, sizeof(dp));
        int res = solve(0, 0, n - 1, grid); 
        
        return res;
    }
};
