class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for(auto x:mines)
        {
            int a= x[0];
            int b= x[1];
            grid[a][b]=0;
        }
        vector<vector<int>> left, right, top, bottom;
        left= right= top=bottom= grid;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x= n-i-1;
                int y= n-j-1;
                
                if(i>0 and top[i][j])
                    top[i][j]+= top[i-1][j];
                if(j>0 and left[i][j])
                    left[i][j]+= left[i][j-1];
                if((y<n-1) and right[x][y])
                    right[x][y]+= right[x][y+1];
                if((x<n-1) and bottom[x][y])
                    bottom[x][y]+= bottom[x+1][y];
            }
        }
        int ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans= max(ans, min({left[i][j], right[i][j], top[i][j], bottom[i][j]}));
            }
        }
        return ans;
    }
};