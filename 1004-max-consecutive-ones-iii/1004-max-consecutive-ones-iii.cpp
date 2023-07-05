class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0;;
        int n=nums.size();
        int i;
        for(i=0; i<n; i++)
        {
            if(nums[i]==0) k--;
            if(k<0 and nums[j++]==0)
                k++;
        }
        return i-j;
    }
};