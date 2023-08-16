class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n= pairs.size();
        vector<int> dp(n+1, 1);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if((pairs[j][0] <pairs[i][0]) and (1+dp[j] >dp[i]) and (pairs[j][1] <pairs[i][0]))
                    dp[i]= 1+dp[j];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};