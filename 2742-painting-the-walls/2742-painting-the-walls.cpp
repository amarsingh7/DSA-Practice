class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n= cost.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++)
        {
            dp[n][i]= 1e9;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int remain=1; remain<=n; remain++)
            {
                int paint= cost[i]+dp[i+1][max(0, remain-time[i]-1)];
                int notpaint= dp[i+1][remain];
                
                dp[i][remain]= min(paint, notpaint);
            }
        }
        return dp[0][n];
    }
};