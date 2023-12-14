class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        
        vector<vector<int>> diff(r, vector<int>(c, 0));
        int count=0;
        
        vector<int> row, col;
        
        for(int i=0; i<r; i++)
        {
            int rowc1=0;
            for(int k=0; k<c; k++)
            {
                if(grid[i][k] ==1)
                    rowc1++;
            }
            row.push_back(rowc1);
        }
        
        for(int i=0; i<c; i++)
        {
            int colc1=0;
            for(int k=0; k<r; k++)
            {
                if(grid[k][i]==1)
                    colc1++;
            }
            col.push_back(colc1);
        }
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                diff[i][j]= row[i] +col[j] - (c-row[i]) - (r-col[j]);
            }
        }
        
        return diff;
    }
};