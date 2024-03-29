//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int e, int f) 
    {
         vector<vector<int>> dp(f+1, vector<int>(e+1, 0));
        
        int m=0;
        
        while(dp[m][e] <f)
        {
            m++;
            
            for(int i=1; i<=e; i++)
                dp[m][i]= dp[m-1][i-1] + dp[m-1][i]+1;
        }
        
        return m;
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends