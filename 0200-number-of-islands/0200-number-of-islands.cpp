class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        
        int n= grid.size();
        int m= grid[0].size();
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid, i, j);
                    count +=1;
                }
            }
            
        }
        return count;
    }
            
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
        {
            return;
        }
        if(grid[i][j]=='2' || grid[i][j]=='0')
            return;
        
        grid[i][j]='2';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        
    }
};