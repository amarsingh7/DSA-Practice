class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m= grid.size();
        int n = grid[0].size()-1;
        
        int ans=0;
        for(int i=0; i<m; i++)
        {
            int start=0;
            int end= n;
            while(start<=end)
            {
                int mid= start +(end-start)/2;
                if(grid[i][mid]>=0)
                {
                    start= mid+1;
                }
                else
                    end= mid-1;
            }
            ans+= (m-i)*(n-start+1);
            n= start-1;
            
        }
        return ans;
    }
};