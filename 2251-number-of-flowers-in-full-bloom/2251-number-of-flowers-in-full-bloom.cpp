class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        
        for(auto x:flowers)
        {
            start.push_back(x[0]);
            end.push_back(x[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        vector<int> ans;
        for(auto p:people)
        {
            int first= upper_bound(start.begin(), start.end(), p)- start.begin();
            int last= lower_bound(end.begin(), end.end(), p)- end.begin();
            
            ans.push_back(first-last);
        }
        return ans;
    }
};