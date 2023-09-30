class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans=0, check= INT_MAX;
        
        for(auto x:nums)
        {
            check &= x;
            if(check==0)
                ans++, check= INT_MAX;
        }
        return max(1, ans);
    }
};