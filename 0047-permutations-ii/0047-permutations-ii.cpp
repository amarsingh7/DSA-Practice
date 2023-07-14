class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, int index)
    {
        if(index== nums.size()-1)
        {
            if(find(ans.begin(), ans.end(), nums)==ans.end())
                ans.push_back(nums);
            return;
        }   
        for(int i= index; i<nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(nums, ans, index+1);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
        backtrack(nums, ans, 0);
        
        return ans;
    }
};