class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int r= img.size();
        int c= img[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int sum=0, count=0;
                for(int x= i-1; x<=i+1; x++)
                {
                    for(int y= j-1; y<=j+1; y++)
                    {
                        if(x>= 0 and x<r and y>=0 and y<c)
                        {
                            sum+= img[x][y];
                            count++;
                        }
                    }
                }
                ans[i][j]= sum/count;
            }
        }
        return ans;
    }
};