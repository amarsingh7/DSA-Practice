class Solution {
public:
    int sum(vector<int> nums)
    {
        int ans=0;
        for(auto x:nums)
            ans+= x;
        return ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = sum(nums);
        while (left < right) 
        {
            int mid = (left + right) / 2;
            int need = 1, cur = 0;
            for (int i = 1; i < nums.size() && need <=k; i++)
            {
                cur += nums[i-1]; 
                if (cur + nums[i] > mid)
                    cur = 0, need++;
            }
            if (need > k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};