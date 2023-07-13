class Solution {
public:
    
    int solve(vector<int> &nums, vector<int> &dp, int target, int idx)
    {
        if(idx==nums.size()-1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int ans= INT_MIN;
        for(int i= idx+1; i<nums.size(); i++)
        {
            if(abs(nums[i]-nums[idx]) <=target)
                ans = max(ans, 1+solve(nums, dp, target, i));
        }
        return dp[idx]= ans;
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int ans= INT_MIN;
        
        int n=nums.size();
       
        vector<int> dp(n, -1);
        ans= solve(nums, dp, target, 0);
        
        if(ans>0)
            return ans;
        return -1;
    }
};