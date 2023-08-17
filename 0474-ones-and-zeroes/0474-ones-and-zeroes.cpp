class Solution {
public:
    
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<pair<int, int>> counts;
    
    for (const string& str : strs) {
        int zeros = 0, ones = 0;
        for (char ch : str) {
            if (ch == '0') zeros++;
            else ones++;
        }
        counts.emplace_back(zeros, ones);
    }

    sort(counts.begin(), counts.end(), [](const auto& a, const auto& b) {
    if (a.first == b.first) {
            return a.second < b.second; // If zeroes are the same, sort by ones
        }
        return a.first < b.first;
    });

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (const auto& p : counts) {
        for (int i = m; i >= p.first; i--) {
            for (int j = n; j >= p.second; j--) {
                dp[i][j] = max(dp[i][j], dp[i - p.first][j - p.second] + 1);
            }
        }
    }

    return dp[m][n];
}

};