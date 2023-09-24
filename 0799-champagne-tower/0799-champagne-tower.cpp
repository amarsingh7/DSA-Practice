class Solution {
public:
    double champagneTower(int poured, int qrow, int qglass) {
        
        double dp[102][102];
        memset(dp, 0, sizeof(dp));
        dp[0][0]= (double)poured;
        
        for(int i=0; i<=qrow; i++)
        {
            for(int j=0; j<=i; j++)
            {
                double remain= (dp[i][j]-1.0)/2.0;
                if(remain >0)
                {
                    dp[i+1][j] += remain;
                    dp[i+1][j+1] += remain;
                }
            }
        }
            
        
        return min(dp[qrow][qglass], 1.0);
    }
};
