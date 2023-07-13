class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++)
        {
            nums.push_back(i);
        }
        string ans="";
        for(int i=0; i<k-1; i++)
        {
            next_permutation(nums.begin(), nums.end());
        }
        for(int i=0; i<nums.size(); i++)
            ans= ans+ to_string(nums[i]);
        return ans;
    }
};