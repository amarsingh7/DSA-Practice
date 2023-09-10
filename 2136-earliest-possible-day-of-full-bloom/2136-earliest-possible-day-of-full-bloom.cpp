class Solution {
public:
    int earliestFullBloom(vector<int>& tplant, vector<int>& tgrow) {
        int m= tplant.size();
        
        vector<pair<int, int>> vp;
        for(int i=0; i<m; i++)
        {
            vp.push_back({tgrow[i], tplant[i]});
        }
        sort(vp.begin(), vp.end());
        int res=0;
        for(auto x:vp)
        {
            res= max(res, x.first)+ x.second;
        }
        
        return res;
    }
};