class Solution {
public:
    int memo[100][100][100] = {};
    int removeBoxes(vector<int>& boxes) {
        return dp(boxes, 0, boxes.size() - 1, 0);
    }
    int dp(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (memo[l][r][k] > 0) return memo[l][r][k];
        int ll = l, kk = k;

        while (l+1 <= r && boxes[l] == boxes[l+1]) { // Increase both `l` and `k` if they have consecutive colors with `boxes[l]`
            l += 1;
            k += 1;
        }
        int ans = (k+1) * (k+1) + dp(boxes, l+1, r, 0); // Remove all boxes which has the same with `boxes[l]`
        for (int m = l + 1; m <= r; ++m) // Try to merge non-contiguous boxes of the same color together
            if (boxes[m] == boxes[l])
                ans = max(ans, dp(boxes, m, r, k+1) + dp(boxes, l+1, m-1, 0));
        return memo[ll][r][kk] = ans;
    }
};