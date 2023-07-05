class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1;
        int i=0;
        int start;
        
        for(start=0; start<nums.size(); start++)
        {
            if(nums[start]==0) k--;
            if(k<0 and nums[i++]==0)
                k++;
        }
        return start-i-1;
    }
};