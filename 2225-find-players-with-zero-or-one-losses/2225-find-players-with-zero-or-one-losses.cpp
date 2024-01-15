class Solution {
public:
    int n= 1e5;
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> ans, vans;
        
        int m= matches.size();
        unordered_map<int, int> mp1, mp2;
        
        for(auto x:matches)
        {
            if(mp2[x[0]]==0)  mp2[x[0]]=0;
            mp2[x[1]]++;
        }
        
        for(auto x:mp2)
        {
            if(x.second ==0)
                ans.push_back(x.first);
            if(x.second ==1)
                vans.push_back(x.first);
        }
        sort(ans.begin(), ans.end());
        sort(vans.begin(), vans.end());
        return {ans, vans};
    }
};