class Solution {
public:
    int dp[501][501];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        
        for (int num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (secondMax < 0 && firstMin > 0) {
            return firstMin * secondMax;
        } 

        for(int i=0; i<=nums1.size(); i++)
            for(int j=0; j<=nums2.size(); j++)
                dp[i][j]=0;
        
        for (int i = nums1.size() - 1; i >= 0; i--) {
            for (int j = nums2.size() - 1; j >= 0; j--) {
                int use = nums1[i] * nums2[j] + dp[i + 1][j + 1];
                dp[i][j] = max(use, max(dp[i + 1][j], dp[i][j + 1]));
            }
        }
        
        return dp[0][0];
    }
};