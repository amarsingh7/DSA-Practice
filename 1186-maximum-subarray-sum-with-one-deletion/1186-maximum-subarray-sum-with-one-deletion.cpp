class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=nums[0];
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        dp[0][0]= nums[0];
        for(int i=1; i<n; i++)
        {
            dp[i][0]= max(nums[i], dp[i-1][0]+nums[i]);
            dp[i][1]= max(nums[i], max(dp[i-1][1]+nums[i], dp[i-1][0]));
            ans= max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};