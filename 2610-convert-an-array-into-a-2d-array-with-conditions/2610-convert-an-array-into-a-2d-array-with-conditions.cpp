class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        
        vector<int> freq(n+1, 0);
        
        for(auto x:nums)
        {
            if(freq[x] >=ans.size())
                ans.push_back({});
            ans[freq[x]].push_back(x);
            freq[x]++;
        }
        return ans;
    }
};