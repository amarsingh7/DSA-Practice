class Solution {
public:
    bool dfs(int i, int j, int m, int n, int mid, vector<vector<int>>& ht, vector<vector<int>>&v)
    {
        if(i==m-1 and j==n-1)
            return true;
        v[i][j]= 1;
        int direction[4][2]= {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(auto d:direction)
        {
            int ui= i+d[0];
            int uj= j+d[1];
            if(ui>=0 and uj>=0 and ui<=m-1 and uj<=n-1 and !v[ui][uj] and abs(ht[i][j] - ht[ui][uj]) <=mid){
               if(dfs(ui, uj, m, n, mid, ht, v))
                    return true; 
            } 
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        int s=0;
        int e= INT_MAX, ans= INT_MAX;
        
        while(s<=e)
        {
            int mid= s+(e-s)/2;
            vector<vector<int>>v (m+1, vector<int>(n+1, 0));
            if(dfs(0, 0, m, n, mid, heights, v))
            {
                ans= min(ans, mid);
                e= mid-1;
            }
            else
                s= mid+1;
        }
        return ans;
  }
    
};