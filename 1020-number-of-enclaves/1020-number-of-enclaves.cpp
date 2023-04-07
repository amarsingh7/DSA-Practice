class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        
        for(int i=0; i<r; i++)
        {
            if(grid[i][0])
                dfs(grid, i, 0);
            if(grid[i][c-1])
                dfs(grid, i, c-1);
        }
        
        for(int j=0; j<c; j++)
        {
            if(grid[0][j])
                dfs(grid, 0, j);
            if(grid[r-1][j])
                dfs(grid, r-1, j);
        }
        
        int ans=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j])
                    ans++;
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &v, int i, int j)
    {
        int m= v.size();
        int n= v[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n || v[i][j] !=1)
            return;
        v[i][j]=0;
        
        dfs(v, i-1, j);
        dfs(v, i+1, j);
        dfs(v, i, j-1);
        dfs(v, i, j+1);
    }
};