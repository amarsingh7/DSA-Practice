class Solution {
public:
    int solve(vector<int> prices)
    {
        int res=0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]>prices[i-1])
              res+= prices[i]- prices[i-1];  
        }
        return res;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        if(k> n/2)
            return solve(prices);
        int dp[k+1][n];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=k; i++)
        {
            int tmpmax= -prices[0];
            for(int j=1; j<n; j++)
            {
                dp[i][j]= max(dp[i][j-1], prices[j]+tmpmax);
                tmpmax= max(tmpmax, dp[i-1][j-1]- prices[j]);
            }
        }
        return dp[k][n-1];
    }
};

