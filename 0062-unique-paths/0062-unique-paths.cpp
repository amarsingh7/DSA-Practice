class Solution {
public:
    int dp[101][101];
    int ans(int i, int j, int n, int m)
    {
        if(i == (n-1) && j == (m-1))
            return 1;
        if(i >=n || j >=m) 
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int left= ans(i+1,j,n,m);
        int right= ans(i,j+1,n,m);
        dp[i][j]= left+right;
        
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return ans(0, 0, m, n);
    }
};