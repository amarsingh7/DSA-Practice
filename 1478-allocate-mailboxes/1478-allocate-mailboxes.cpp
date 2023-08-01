class Solution {
public:
    int dp[101][101];

    int solve(vector<int>& houses, int k, int cur, int curk) {
        // Base case: All houses are processed
        if (cur == houses.size()) {
            // If required number of mailboxes is reached, return 0 (target achieved)
            if (curk == k)
                return 0;
            // If required number of mailboxes is not reached, return infinity (not possible)
            return INT_MAX;
        }
        
        if (curk == k)
            return INT_MAX;
        
        if (dp[cur][curk] != -1)
            return dp[cur][curk];

        long long ans = INT_MAX;
        for (int i = cur; i < houses.size(); i++) {
            long long dist = 0;
            // getting median of current subarray
            int medi = houses[(i + cur) / 2];
            // Calculate the total cost to allocate a mailbox in the current subarray
            for (int j = cur; j <= i; j++) {
                dist += abs(medi - houses[j]);
            }
            // Find the minimum cost by recursively exploring the next subarray
            ans = min(ans, (long long)solve(houses, k, i + 1, curk + 1) + dist);
        }
       
        dp[cur][curk] = ans;
        return ans;
    }

    // Main function to find the minimum distance to allocate mailboxes
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());

        memset(dp, -1, sizeof(dp));
        
        // start with cur=0 in houses && curk=0 used mailboxes.
        return solve(houses, k, 0, 0);
    }
};
