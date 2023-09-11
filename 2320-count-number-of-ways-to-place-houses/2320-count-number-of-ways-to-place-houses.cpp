class Solution {
public:
    long long mod= 1e9+7;
    long long helper( int n, vector<long long> &dp){
        if(n == 1) return dp[n] = 2;  
        if(n == 2) return dp[n] =  3;       
        if(dp[n] != -1) return dp[n];


        long long pick= helper(n-2,dp)%mod;
        long long npick= helper(n-1,dp)%mod; 

        return dp[n] = (pick+npick)%mod;
    } 
    int countHousePlacements(int N) {
         vector<long long> dp(N+1,-1);
         helper(N, dp);
        
         return (dp[N]*dp[N])%mod;    
    }
};