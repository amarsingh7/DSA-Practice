class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int mod= 1e9+7;
        vector<long long> fac(n+1, 0);
        fac[0]=1;
        for(int i=1; i<=n; i++)
            fac[i]= (fac[i-1]*i)%mod;
        long long dp[n+1][goal+1];
        
        for(int i=k+1; i<=n; i++)
        {
            for(int j=i; j<=goal; j++)
            {
                if((i==j) ||(i==k+1))
                    dp[i][j]= fac[i];
                else
                    dp[i][j]= (dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - k))  % mod;
            }
        }
        return (int) dp[n][goal];
    }
};