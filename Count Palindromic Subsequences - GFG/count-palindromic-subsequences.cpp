//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete below method */
    
    long long int  countPS(string str)
    {
       //Your code here
       long long n= str.size();
       long long dp[n][n];
       int mod= 1e9 +7;
       for(int gap=0; gap<n; gap++)
       {
           for(int i=0, j=gap; j<n; j++, i++)
           {
                if(gap==0)
                    dp[i][j]= 1;
                else if(gap==1)
                    dp[i][j]= str[i]==str[j] ?3:2;
                else{
                    if(str[i]==str[j])
                        dp[i][j]= dp[i][j-1] +dp[i+1][j]+1;
                    else
                        dp[i][j]= (dp[i][j-1] +dp[i+1][j]- dp[i+1][j-1])%mod;
                }
           }
       }
       return dp[0][n-1]>0 ? dp[0][n-1] %mod : (dp[0][n-1] +mod)%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends