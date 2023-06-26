//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    
    int mod= 1e9+7;
    vector<vector<int>> dp;
    int ans(int n, int r)
    {
        if(n<r)
            return 0;
        if(r==1)
            return n;
        if(n==r)
            return 1;
        if(dp[n][r] != -1)
            return dp[n][r];
        dp[n][r]= (ans(n-1, r-1)%mod + ans(n-1, r)%mod )%mod;
        return dp[n][r];
    }
    int nCr(int n, int r){
        // code here
        dp.resize(n+1, vector<int>(r+1, -1));
        return ans(n, r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends