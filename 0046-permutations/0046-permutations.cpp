class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &ans, int index)
    {
        if(index== nums.size()-1)
        {
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        
        backtrack(nums, ans, 0);
        return ans;
       
    }
};