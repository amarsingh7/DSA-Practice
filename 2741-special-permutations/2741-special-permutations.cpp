class Solution {
public:
    
    vector<vector<int>> dp;
    int mod= 1e9+7;
    int fck(vector<int> &nums, int pindex, int cindex, int musk)
    {
        if(cindex==nums.size())
            return 1;
        if(dp[pindex+1][musk] != -1)
            return dp[pindex+1][musk];
        int res=0;
        for(int j=0; j<nums.size(); j++)
        {
            if(musk & (1<<j))
                continue;
            if(pindex==-1 || nums[pindex]% nums[j]==0 || nums[j]% nums[pindex]==0)
            {
                res+= fck(nums, j, cindex+1, musk | (1<<j));
                res %= mod;
            }  
                
        }
        dp[pindex+1][musk]= res;
        return dp[pindex+1][musk];
    }
    
    int specialPerm(vector<int>& nums) {
        
        dp.resize(20, vector<int>((1<<14)+5 , -1));
        return fck(nums, -1, 0, 0);
        
    }
};