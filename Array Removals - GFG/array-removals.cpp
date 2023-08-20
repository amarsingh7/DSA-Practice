//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int dp[101][101];
    int solve(vector<int> &arr, int k, int i, int j)
    {
        if(i >=j)
            return 0;
        else if(arr[j]-arr[i] <=k)
            return 0;
        else if(dp[i][j] != -1)
            return dp[i][j];
        else if(arr[j] - arr[i] >k)
        {
            dp[i][j]= 1+min(solve(arr, k, i+1, j), solve(arr, k, i, j-1));
        }
        return dp[i][j];
    }
    int removals(vector<int>& arr, int k){
        //Code here
        int n= arr.size();
        sort(arr.begin(), arr.end());
        memset(dp, -1, sizeof(dp));
        return solve(arr, k, 0, n-1);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends