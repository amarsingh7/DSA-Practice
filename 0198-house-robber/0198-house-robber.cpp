class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+2, 0);
        for(int i=n-1; i>=0; i--)
        {
            int skip= dp[i+1];  // skipping cur index
            int take= nums[i]+ dp[i+2]; // taking the cur index
            dp[i]= max(skip, take);  // storing the max
        }
        return dp[0];
    }
};