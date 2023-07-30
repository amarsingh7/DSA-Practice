class Solution {
public:
   
    int dp[1001][1001];
    int longestCommonSubsequence(string s, string r) {
        int m= s.size();
        int n= r.size();
        
        memset(dp, 0, sizeof(dp));
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