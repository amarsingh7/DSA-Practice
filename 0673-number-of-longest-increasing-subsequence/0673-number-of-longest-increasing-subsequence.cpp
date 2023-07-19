class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j])
                {
                    if(dp[i]<dp[j]+1)
                        dp[i]= dp[j]+1, count[i]=0;
                    if(dp[i]==dp[j]+1)
                        count[i] += count[j];
                }
                    
            }
        }
        int ans= *max_element(dp.begin(), dp.end());
        int res=0;
        for(int i=0; i<n; i++)
        {
            if(dp[i]==ans)
                res+= count[i];
        }
        return res;
    }
};