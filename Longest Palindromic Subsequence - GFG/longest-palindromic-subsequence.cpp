//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int dp[1001][1001];
    int lcs(int i, int j, string &str, string &txt)
    {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (str[i] == txt[j])
            return 1 + lcs(i - 1, j - 1, str, txt);
        return dp[i][j] = max(lcs(i - 1, j, str, txt), lcs(i, j - 1, str, txt));
    }

    int longestPalinSubseq(string str)
    {
        int n = str.size();
        string txt(str.rbegin(), str.rend());
        memset(dp, -1, sizeof(dp));
        return lcs(n - 1, n - 1, str, txt);
    }

};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends