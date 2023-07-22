class Solution {
public:
    
    double dp[26][26][101];
    
    double find(int N, int K, int r, int c)
    {
        if(r<0||c<0||r>=N||c>=N) return 0;
        if(K==0) return 1;
        if(dp[r][c][K]!=0) 
            return dp[r][c][K];
        double p = find(N,K-1,r+1,c+2) + find(N,K-1,r-1,c-2) +
                   find(N,K-1,r+2,c+1) + find(N,K-1,r-2,c-1) +
                   find(N,K-1,r+1,c-2) + find(N,K-1,r-1,c+2) +
                   find(N,K-1,r+2,c-1) + find(N,K-1,r-2,c+1);
        p /= 8;
        dp[r][c][K] = p;
        return p;
    }
    double knightProbability(int N, int K, int r, int c) {
        return find(N,K,r,c);
    
    }
};