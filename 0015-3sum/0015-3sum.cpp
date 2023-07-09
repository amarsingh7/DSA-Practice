class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        for(int i = 0; i < n; i++) 
        {
            int low = i + 1, high = n - 1;
            while(low < high) 
            {
                if(nums[low] + nums[high] < -nums[i])
                    low++;
                else if(nums[low] + nums[high] > -nums[i])
                 high--;
                else
                {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++; high--;
                }
                    
            }
        }
        set<vector<int>> st(ans.begin(), ans.end());
        ans.assign(st.begin(), st.end());
        return ans;
    }
};