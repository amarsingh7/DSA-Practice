class Solution {
public:
    int dp[501][501];
    int minDistance(string a, string b) {
        int m= a.size();
        int n= b.size();
        int i=0, j=0;
        
//         if(a.find(b) != string::npos)
//             return m-n;
//         if(b.find(a) !=string::npos)
//             return n-m;
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]= dp[i-1][j-1] +1;
                else
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return m+n- 2*dp[m][n];
    }
};