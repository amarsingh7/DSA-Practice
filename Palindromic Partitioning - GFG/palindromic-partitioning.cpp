//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int palindromicPartition(string str)
    {
        // code here
        int n= str.size();
        vector<int> dp(n, INT_MAX);
        vector<vector<bool>> palin(n, vector<bool>(n, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if(str[i]==str[j] and (i-j<=1 || palin[j+1][i-1]))
                {
                    palin[j][i]= true;
                    if(j==0)
                        dp[i]=0;
                    else
                        dp[i]= min(dp[i], dp[j-1]+1);
                }
                    
            }
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends