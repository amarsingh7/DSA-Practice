class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0;
        int n= nums.size();
        int i=0, j= n-1;
        
        while(i<j)
        {
            ans= max(ans, nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};