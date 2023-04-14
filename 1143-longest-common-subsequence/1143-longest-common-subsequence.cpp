class Solution {
public:
    int lcs(string &s, string &r, int m, int n, vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return 0;
        if(s[m-1]==r[n-1])
            //return 1+lcs(s, r, m-1, n-1);
            return dp[m][n]= 1+ lcs(s, r, m-1, n-1, dp);
        if(dp[m][n] != -1)
            return dp[m][n];
        else
            return dp[m][n]= max(lcs(s, r, m-1, n, dp), lcs(s, r, m, n-1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m= text1.size();
        int n= text2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return lcs(text1, text2, m, n, dp);
    }
};