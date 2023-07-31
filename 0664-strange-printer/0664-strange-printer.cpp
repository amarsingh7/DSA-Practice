class Solution {
public:
    int dp[101][101];
    int strangePrinter(string s) {
        
        s.erase(unique(s.begin(), s.end()), s.end());
        int n = s.size();
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        
        for (int k = 1; k < n; ++k) 
        {
            for (int i = 0; i < n - k; ++i) {
                int j = i + k;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } 
                else {
                    dp[i][j] = INT_MAX;
                    for (int l = i; l < j; ++l) {
                        dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};