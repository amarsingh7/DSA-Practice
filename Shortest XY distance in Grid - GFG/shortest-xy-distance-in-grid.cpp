//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        int res=INT_MAX;
        
        vector<pair<int, int>> r;
        vector<pair<int, int>> c;
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(grid[i][j]=='X')
                {
                    r.push_back({i, j});
                }
                if(grid[i][j]=='Y')
                {
                    c.push_back({i, j});
                }
            }
        }
        for(auto x:r)
        {
            int xi= x.first;
            int xj= x.second;
            
            for(auto y:c)
            {
                int yi= y.first;
                int yj= y.second;
                
                res= min(res, abs(xi-yi)+abs(xj-yj));
                
                if(res==1) break;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends