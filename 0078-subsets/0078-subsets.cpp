class Solution {
public:
    void subset(vector<vector<int>> &vec, vector<int> nums, vector<int>&temp, int index)
    {
        if(index==nums.size())
        {
            vec.push_back(temp);
            return;
        }
        subset(vec, nums, temp, index+1);
        temp.push_back(nums[index]);
        subset(vec, nums, temp, index+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> temp;
        int index=0;
        subset(vec, nums, temp, 0);
        return vec;
    }
};