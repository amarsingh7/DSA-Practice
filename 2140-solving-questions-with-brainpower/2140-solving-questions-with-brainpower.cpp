class Solution {
public:
    long long mostPoints(vector<vector<int>>& qs) {
        long long dp[200001]= {};
        for(int i=qs.size()-1; i>=0; i--)
        {
            dp[i]= max(qs[i][0] + dp[qs[i][1] +i+1], dp[i+1]);
        }
        return dp[0];
    }
};