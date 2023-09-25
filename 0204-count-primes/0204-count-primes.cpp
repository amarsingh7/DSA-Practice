class Solution {
public:
    int countPrimes(int n) {
        vector<bool> dp(n+1, true);
        dp[0]= false;
        dp[1]= false;
        
        for(long long i=2; i<n; i++)
        {
            if(dp[i])
            {
                for(long long j=(i*i); j<n; j+=i)
                    dp[j]= false;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(dp[i])
                ans++;
        }
        return ans;
    }
};