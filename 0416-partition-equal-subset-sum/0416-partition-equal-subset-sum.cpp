class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum= accumulate(nums.begin(), nums.end(), 0L);
        
        if((sum&1) ==1)
            return false;
        sum/=2;
        
        vector<bool> dp(sum+1, false);
        dp[0]= true;
        
        for(auto x:nums)
        {
            for(int i=sum; i>0; i--)
            {
                if(i>=x)
                    dp[i]= dp[i] || dp[i-x];
            }
        }
        return dp[sum];
    }
};