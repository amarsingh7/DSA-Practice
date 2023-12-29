class Solution {
public:
    int minDifficulty(vector<int>& jd, int D) {
        int n= jd.size();
        int sum=0, maxd=0;
        vector<int> dp(n+1, 1e9);
        dp[n]=0;
        int inf= 1e9;
        
        for(auto x:jd)
            sum+= x;
        if(jd.size() <D)
            return -1;
        if(jd.size()== D)
            return sum;
        for(int d=1; d<=D; d++)        
        {
            for (int i = 0; i <= n - d; ++i) {
                maxd = 0, dp[i] = inf;
                for (int j = i; j <= n - d; ++j) {
                    maxd = max(maxd, jd[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
};