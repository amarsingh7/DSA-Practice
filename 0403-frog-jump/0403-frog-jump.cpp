class Solution {
public:
    
    
    bool canCross(vector<int>& stones) {
        int m= stones.size(); 
        vector<vector<int>> dp(m, vector<int>(m + 1));
       
        if(stones[1] == 1){
            dp[1][1] = true; 
            // with a jump of step size 1, the frog reaches the 1st position.
        }
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = i + 1; j < stones.size(); ++j)
            {
                if(int diff = stones[j] - stones[i]; diff <= j)
                {
                    dp[j][diff] = dp[i][diff-1] || dp[i][diff] || dp[i][diff+1];
                }
            }
        }
        return accumulate(dp[m-1].begin(), dp[m-1].end(), 0) > 0;
    }
};