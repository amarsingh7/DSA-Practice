class Solution {
public:
    int dp[101][101];
    int solve(vector<int>& houses, int k, int cur, int curk) {
        if (cur == houses.size()) {
            if (curk == k)
                return 0;
            return INT_MAX;
        }
        if (curk == k)
            return INT_MAX;
        if (dp[cur][curk] != -1)
            return dp[cur][curk];

        long long ans = INT_MAX;
        for (int i = cur; i < houses.size(); i++) {
            long long dist = 0;
            int medi = houses[(i + cur) / 2];
            for (int j = cur; j <= i; j++) {
                dist += abs(medi - houses[j]);
            }
            ans = min(ans, (long long)solve(houses, k, i + 1, curk + 1) + dist); 
        }
        dp[cur][curk] = ans;
        return ans;
    }
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());

        memset(dp, -1, sizeof(dp));

        return solve(houses, k, 0, 0);
    }
};
