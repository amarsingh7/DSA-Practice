
class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1);
    dp[n] = true;

    for (int i = n - 1; i >= 0; i--) {
        string sub;
        for (int j = i; j < n; j++) {
            for (const string& word : wordDict) {
                if (word == s.substr(i, j - i + 1) && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[0];
}

};