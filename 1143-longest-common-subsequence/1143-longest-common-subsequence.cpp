class Solution {
public:
    // int lcs(string &s, string &r, int m, int n, vector<vector<int>> &dp)
    // {
    //     if(m==0 || n==0)
    //         return 0;
    //     if(s[m-1]==r[n-1])
    //         //return 1+lcs(s, r, m-1, n-1);
    //         return dp[m][n]= 1+ dp[m-1][n-1];
    //     if(dp[m][n] != -1)
    //         return dp[m][n];
    //     else
    //         return dp[m][n]= max(dp[m-1][n], dp[m][n-1]);
    // }
    int longestCommonSubsequence(string s, string r) {
        int m= s.size();
        int n= r.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==r[j-1])
                    dp[i][j]= dp[i-1][j-1] +1;
                else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};