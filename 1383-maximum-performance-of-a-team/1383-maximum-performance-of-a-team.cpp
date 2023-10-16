class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& effi, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        vector<pair<int, int>> vp;
        for(int i=0; i<n; i++)
        {
            vp.push_back({effi[i], speed[i]});
        }
        long res=0, sum=0;
        sort(vp.rbegin(), vp.rend());
        for(auto &x:vp)
        {
            pq.emplace(x.second);
            sum += x.second;
            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * x.first);
        }
        return res % (int)(1e9+7);

    }
};