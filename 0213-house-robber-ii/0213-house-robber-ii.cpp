class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n+2, 0);
        vector<int> dp2(n+2, 0);
        if(n==3 || n==2)
            return *max_element(nums.begin(), nums.end());
        if(n==1)
            return nums[0];
        for(int i=n-1; i>=1; i--)
        {
            int skip= dp1[i+1];
            int take= nums[i]+ dp1[i+2];
            dp1[i]= max(skip, take);
        }
        for(int i=n-2; i>=0; i--)
        {
            int skip= dp2[i+1];
            int take= nums[i]+ dp2[i+2];
            dp2[i]= max(skip, take);
        }
        return dp1[1]> dp2[0]? dp1[1]:dp2[0];
    }
};