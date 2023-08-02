class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int m= worker.size();
        int n= difficulty.size();
        
        vector<pair<int, int>> jobs;
        int res = 0, i = 0, best = 0;
        for (int j = 0; j < n; ++j)
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        for (int & ability : worker) {
            while (i < n && ability >= jobs[i].first)
                best = max(jobs[i++].second, best);
            res += best;
        }
        return res;
    }
};