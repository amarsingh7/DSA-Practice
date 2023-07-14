class Solution {
public:
    void backtrack(vector<int> nums, vector<vector<int>> &ans, int index)
    {
        if(index== nums.size()-1)
        { 
            ans.push_back(nums);
            return;
        }   
        for(int i= index; i<nums.size(); i++)
        {
            if(index !=i and nums[index] ==nums[i])
                continue;
            swap(nums[index], nums[i]);
            backtrack(nums, ans, index+1); 
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        backtrack(nums, ans, 0);
         
        return ans;
    }
    
};