class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto x:tasks)
            mp[x]++;
        
        int ans=0;
        for(auto x:mp)
        {
            if(x.second ==1)
                return -1;
            ans+= (x.second +2)/3;
        }
        return ans;
    }
};