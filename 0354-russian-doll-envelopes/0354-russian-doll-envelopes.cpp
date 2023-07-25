class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    if (n == 0) return 0;

    // Sort envelopes based on width in ascending order.
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); 
        // If width is same, sort by height in descending order.
    });

    vector<int> dp;

    for (vector<int>& envelope : envelopes) {
        int height = envelope[1];
        auto it = lower_bound(dp.begin(), dp.end(), height);
        if (it == dp.end())
            dp.push_back(height);
        else
            *it = height;
    }

    return dp.size();
}

};