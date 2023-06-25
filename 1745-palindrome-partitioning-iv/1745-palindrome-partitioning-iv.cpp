class Solution {
public:
    bool checkPartitioning(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false)); 
    
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i; j<n; j++)
        {
            int len= j-i+1;
            if(len==1)
                dp[i][j]= true;
            else if(len==2)
                dp[i][j]= s[i]==s[j];
            else
                dp[i][j]= (s[i]==s[j]) and (dp[i+1][j-1]);
        }
    }
    for(int p=0; p<n; p++)
    {
        for(int s=p+2; s<n; s++)
        {
            auto left= dp[0][p];
            auto mid= dp[p+1][s-1];
            auto right= dp[s][n-1];
            if(left and mid and right)
                return true;
        }
    } 
    return false;
    
}

};