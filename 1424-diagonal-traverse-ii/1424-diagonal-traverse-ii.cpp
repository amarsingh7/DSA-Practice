class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n= nums.size();
        
        queue<pair<int, int>> q;
        vector<int> ans;
        q.push({0, 0});
        
        while(!q.empty())
        {
            auto x= q.front();
            q.pop();
            ans.push_back(nums[x.first][x.second]);
            
            if(x.second==0 and x.first +1 <nums.size())
                q.push({x.first +1, x.second});
            if(x.second+1 <nums[x.first].size())
                q.push({x.first, x.second +1});
        }
        return ans;
    }
};