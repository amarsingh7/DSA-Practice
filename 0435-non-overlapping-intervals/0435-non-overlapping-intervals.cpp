class Solution {
public:
    
    static bool compa(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
        
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compa);
        int ans= -1;
        int n= intervals.size();
        auto prev= intervals[0];
        
        for(auto x:intervals)
        {
            if(prev[1]> x[0])
                ans++;
            else
                prev= x;
        }
        return ans;
    }
};