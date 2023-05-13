class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int res=INT_MIN;
        for(int i=0; i<nums.size(); i++)
        {
            ans++;
            if(nums[i]==0)
            {
                ans=0;
            }
            res=max(res, ans);
                
        }
        return res;
    }
};