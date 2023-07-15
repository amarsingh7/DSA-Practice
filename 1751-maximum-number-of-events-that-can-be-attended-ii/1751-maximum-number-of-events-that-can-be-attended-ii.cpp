class Solution {
public:
    vector<vector<int>> dp;

// Recursive function to find the maximum value
int dfs(vector<vector<int>>& events, int i, int k) {
    // Base case: No more events to consider or no more available slots (k) to attend events
    if (k == 0 || i >= events.size())
        return 0;

    // If the result is already calculated, return it
    if (dp[i][k] != -1)
        return dp[i][k];

    // Find the index (j) of the next event that starts after the current event ends
    auto j = upper_bound(begin(events) + i, end(events), events[i][1],
        [](int t, const vector<int> &v) { return v[0] > t; }) - begin(events);

    // Calculate the maximum value by either attending the current event and recursively considering the next available events
    // or skipping the current event and considering the next event
    return dp[i][k] = max(events[i][2] + dfs(events, j, k - 1), dfs(events, i + 1, k));
}

int maxValue(vector<vector<int>>& events, int k) {
    // Initialize the dynamic programming table with -1 values
    dp = vector<vector<int>>(events.size(), vector<int>(k + 1, -1));

    // Sort the events based on their start times
    sort(begin(events), end(events));

    // Call the recursive function to find the maximum value
    return dfs(events, 0, k);
}

};