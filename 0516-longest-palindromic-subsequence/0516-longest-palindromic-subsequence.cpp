class Solution {
public:

    int dp[1001][1001];
    int lcs(int i, int j, string &s, string &t)
    {
        if(i<0 || j<0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i]==t[j])
            return 1+ lcs(i-1, j-1, s, t);
        return dp[i][j]= max(lcs(i-1, j, s, t), lcs(i, j-1, s, t));
    }
    
    int longestPalindromeSubseq(string s) {
        string t(s.rbegin(), s.rend());
        int m= s.size();
        int n=m;
        memset(dp, -1, sizeof(dp));
        return lcs(m-1, n-1, s, t);
        
    }
};