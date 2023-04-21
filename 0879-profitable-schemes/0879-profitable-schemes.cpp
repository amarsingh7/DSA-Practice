class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int MOD = 1e9 + 7;
        int m = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        dp[0][0] = 1;
        for (int k = 0; k < m; k++) 
        {
            int g = group[k], p = profit[k];
            for (int i = n; i >= g; i--) 
            {
                for (int j = minProfit; j >= 0; --j) 
                {
                    int cur= (j - p >= 0) ? dp[i - g][j - p]:dp[i - g][0];
                    dp[i][j]= (dp[i][j] + cur) % MOD;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++) 
            ans = (ans + dp[i][minProfit]) % MOD;
        
        return ans;
    }
};