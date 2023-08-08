class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int direc[8][2]= {{1, 2}, {2, 1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {-1, -2}, {-2, -1}};
        int x=0, y=0;
        if(grid[x][y] !=0)
            return false;
        int n= grid.size();
        int count=0, maxcount= n*n -1;
        
        while(count<maxcount)
        {
            count++;
            bool flag=1;
            for(auto d:direc)
            {
                int i= x+d[0];
                int j= y+d[1];
                if(i>=0 and j>=0 and i<n and j<n and grid[i][j]==count)
                {
                    x= i; y=j;
                    flag=0;
                    break;
                }
                    
            }
            if(flag)
                return false;
        }
        return true;
    }
};