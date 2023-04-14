class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vc;
        int n= intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<n; i++)
        {
            if(vc.empty() || vc.back()[1]< intervals[i][0])
              vc.push_back({intervals[i][0], intervals[i][1] });
            
            else
              vc.back()[1] = max(vc.back()[1], intervals[i][1]);
        }
    return vc;
    }
};