class Solution {
public:
    int fib(int n) {
        long long dp[32];
        dp[0]= dp[1]=1;
        
        if(n==0)
            return 0;
        for(int i=2; i<32; i++)
            dp[i]= dp[i-1]+dp[i-2];
        return dp[n-1];
    }
};