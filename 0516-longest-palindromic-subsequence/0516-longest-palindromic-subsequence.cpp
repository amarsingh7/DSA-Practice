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
        
//         vector<int> dp(n), dpp(n);
        
//         for(int i=n-1; i>=0; i--)
//         {
//             dp[i]=1;
//             for(int j=i+1; j<n; j++)
//             {
//                 if(s[i]==s[j])
//                     dp[j]= dpp[j-1] +2;
//                 else
//                     dp[j]= max(dpp[j], dp[j-1]);
//             }
//             dpp= dp;
//         }
//         return dp[n-1];
    }
};