class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
       
        int fans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                    fans= max(fans, bsdk(grid, i, j));
            }
                
        }
            
            
        return fans;
    }
    
    int bsdk(vector<vector<int>> &grid, int i, int j)
    {
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + bsdk(grid, i+1, j) + bsdk(grid, i-1, j) + bsdk(grid, i, j-1) + bsdk(grid, i, j+1);
        }
        return 0;
        
    }
    
};