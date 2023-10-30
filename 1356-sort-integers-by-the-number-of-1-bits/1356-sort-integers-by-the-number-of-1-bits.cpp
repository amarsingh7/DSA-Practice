class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        int n= arr.size();
        
        vector<pair<int, int>> vp;
        for(auto x:arr)
        {
            int bit= bitset<32>(x).count();
            vp.push_back({bit, x});
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> &a, pair<int, int>&b){
           if(a.first==b.first) 
               return a.second <b.second;
            return a.first<b.first;
        });
        for(auto x:vp)
            ans.push_back(x.second);
        return ans;
    }
};