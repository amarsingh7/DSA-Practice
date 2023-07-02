//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r,int c,int ro,int co,vector<vector<int>>&grid,vector<pair<int,int>>&v)
    {
            int m= grid.size();
            int n= grid[0].size();
            if(r<0 || c<0 || r>=m ||c>=n ||grid[r][c]<=0)
                return;
        v.push_back({r-ro, c-co});
        grid[r][c] *= -1;
        dfs(r+1, c, ro, co, grid, v);
        dfs(r-1, c, ro, co, grid, v);
        dfs(r, c+1, ro, co, grid, v);
        dfs(r, c-1, ro, co, grid, v);
        
   }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0)
            return 0;
            
        set<vector<pair<int,int>>>s;
        for(int r=0; r<m; r++)
        {
            for(int c=0; c<n; c++)
            {
                if(grid[r][c] != 1)
                    continue;
                vector<pair<int, int>> v;
                dfs(r, c, r, c, grid, v);
                s.insert(v);
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends