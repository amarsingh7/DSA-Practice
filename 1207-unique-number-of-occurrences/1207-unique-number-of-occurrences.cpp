class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto x:arr)
            mp[x]++;
            
        vector<int> ans;
        for(auto x:mp)
            ans.push_back(x.second);
        sort(ans.begin(), ans.end());
        
        for(int i=1; i<ans.size(); i++)
        {
            if(ans[i]== ans[i-1])
                return false;
        }
        return true;
    }
};