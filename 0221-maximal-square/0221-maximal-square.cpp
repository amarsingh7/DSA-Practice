class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r= matrix.size();
        int c= matrix[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        int side=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(!i || !j || matrix[i][j]=='0')
                    dp[i][j]= matrix[i][j]-'0';
                else
                    dp[i][j]= min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
                
                side= max(side, dp[i][j]);
            }
            
        }
        return side*side;
    }
};