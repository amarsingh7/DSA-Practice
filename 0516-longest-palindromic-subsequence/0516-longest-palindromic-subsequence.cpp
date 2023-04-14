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
    
    int longestPalindromeSubseq(string s) {
        string r;
        r= s;
        int n= s.size();
        int m=n;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return lcs(s, r, n, m, dp);
        
    }
};