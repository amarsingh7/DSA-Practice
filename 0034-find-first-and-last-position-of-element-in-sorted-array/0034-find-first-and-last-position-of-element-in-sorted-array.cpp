class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int x) {
        vector<int> v={-1, -1};
        if(!binary_search(nums.begin(), nums.end(), x))
            return v;
        vector<int> ans(2);
        ans[0]= lower_bound(nums.begin(), nums.end(), x) -nums.begin();
        ans[1]= upper_bound(nums.begin(), nums.end(), x) - ++nums.begin();
        return ans;
    }
};