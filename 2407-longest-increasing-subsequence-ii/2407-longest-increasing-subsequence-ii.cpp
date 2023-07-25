class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int ma=0,dp[318][318];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<nums.size();++i){
            if(i&&nums[i]==nums[i-1])continue;
            int v=nums[i]-1,t=max(nums[i]-k,0),vh=v%317,vn=v/317,vnh=nums[i]%317,vnn=nums[i]/317;
            if(vn==t/317)
                for(int j=v%317;j>=t%317;--j)
                    dp[vnn][vnh]=max(dp[vn][j]+1,dp[vnn][vnh]);
            else{
                for(int j=v%317;j>=0;--j)
                    dp[vnn][vnh]=max(dp[vn][j]+1,dp[vnn][vnh]);
                for(int j=vn-1;j>t/317;--j)
                    dp[vnn][vnh]=max(dp[j][317]+1,dp[vnn][vnh]);
                for(int j=316;j>=t%317;--j)
                    dp[vnn][vnh]=max(dp[t/317][j]+1,dp[vnn][vnh]);
            }
            dp[vnn][317]=max(dp[vnn][vnh],dp[vnn][317]);
            ma=max(ma,dp[vnn][vnh]);
        }
        return ma;
    }
};