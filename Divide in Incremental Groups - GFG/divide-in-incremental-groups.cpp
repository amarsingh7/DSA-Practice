//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ans[101][101][101];
    
    int funca(int pre, int g, int res, int &n, int &k)
    {
        if(g==k and res==0)
            return 1;
        if(g==k  || res==0)
            return 0;
            
        if(ans[pre][g][res] != -1)
            return ans[pre][g][res];
        
        int fans=0;
        for(int i=pre; i<=res; i++)
            fans += funca(i, g+1, res-i, n, k);
            
        return ans[pre][g][res] = fans;
    }
    int countWaystoDivide(int n, int k) {
        memset(ans, -1, sizeof(ans));
        return funca(1, 0, n, n, k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends