class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return {nums[0]};
        vector<int> dp(n, 1);
        sort(nums.begin(), nums.end());
        int maxi=1;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i])
                {
                     dp[i]= 1+dp[j];
                     if(maxi <dp[i])
                        maxi= dp[i];
                }
                
            }
        }
        vector<int> ans;
        int prev= -1;
        for(int i=n-1; i>=0; i--)
        {
            if(dp[i]==maxi and (prev== -1 || prev% nums[i]==0))
            {
                ans.push_back(nums[i]);
                prev= nums[i];
                maxi -= 1;
            }
        }
        return ans;
    }
};