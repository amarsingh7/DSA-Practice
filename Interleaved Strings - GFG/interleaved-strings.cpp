//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool isInterleave(string s1, string s2, string s3) 
    {
        //Your code here
        int m= s1.size();
        int n= s2.size();
        int o= s3.size();
        if(m+n <o)
           return false; 
        bool dp[m+1][n+1];
        memset(dp, false, sizeof(dp));
        dp[0][0]= true;
        
        for(int i=1; i<=m; i++)
        {
            dp[i][0]= dp[i-1][0] and (s1[i-1]==s3[i-1]);
        }
        for(int j=1; j<=n; j++)
        {
            dp[0][j]= dp[0][j-1] and (s2[j-1]==s3[j-1]);
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j]= (dp[i-1][j] and(s1[i-1]==s3[i+j-1])) || 
                          (dp[i][j-1] and (s2[j-1]==s3[i+j-1])) ;
                    
            }
        }
        return dp[m][n];
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends