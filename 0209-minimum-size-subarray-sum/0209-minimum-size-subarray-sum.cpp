class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int res=INT_MAX;
        int j=0, sum=0;
        int n= nums.size();
        while(i<n)
        {
            sum+= nums[i];
            while(sum>=target)
            {
                res= min(res, i -j+1);
                sum -= nums[j];
                j++;
            }
            i++;
        }
        return res==INT_MAX? 0:res;
    }
};