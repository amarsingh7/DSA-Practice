class Solution {
public:
    const int MOD = 1e9+7;
    int dp[31][10000];
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; // only 1 ways to roll zero dice with sum = 0
        
        for (int i=1; i<=n; ++i) 
        {
            for (int t=1; t<=target; ++t) 
            {
                for (int j=1; j<=k; ++j) 
                {
                    if (j <= t)
                        dp[i][t] = (dp[i][t] + dp[i-1][t-j]) % MOD;
                }   
            }
        }
        return dp[n][target];
    }
};