class Solution {
public:
    
    /* 
    DP Appproch     time- O(n*sum)
    Just like 0-1 knapsack where at each iteration we had choice to                   take/leave, here we have 3 choice:
    - Include in l1
    - Include in l2
    - Leave it
    * dp[i][j] = Max sum of group l1 considering the first i rods such that the         difference between the sum of l1 and l2 is (sum of all rods - j)

    */
    
    int tallestBillboard(vector<int>& rods) {
        int n= rods.size();
        int sum= accumulate(rods.begin(), rods.end(), 0);
        int limit= 2*sum;
        vector<vector<int>> dp(n+1, vector<int>(limit, INT_MIN));
        dp[0][sum]=0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<limit; j++)
            {
                // putting in l1
                if((j- rods[i-1]) >= 0 && dp[i-1][j - rods[i-1]] != INT_MIN)
                    dp[i][j] = max(dp[i][j], dp[i-1][j - rods[i-1]] + rods[i-1]);
                // Putting ith in l2
                if ((j+ rods[i-1]) < limit && dp[i-1][j + rods[i-1]] != INT_MIN)
                    dp[i][j] = max(dp[i][j], dp[i-1][j + rods[i-1]]);
                // Ignoring ith rod
                if (dp[i-1][j] != INT_MIN)
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        return dp[n][sum];
    }
    

};