class Solution {
public:
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(f+1, vector<int>(e+1, 0));
        
        int m=0;
        
        while(dp[m][e] <f)
        {
            m++;
            
            for(int i=1; i<=e; i++)
                dp[m][i]= dp[m-1][i-1] + dp[m-1][i]+1;
        }
        
        return m;
    }
};