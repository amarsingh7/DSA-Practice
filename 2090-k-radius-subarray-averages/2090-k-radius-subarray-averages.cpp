class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // When a single element is considered then its averafge will be the number itself only.
        if (k == 0) {
            return nums;
        }

        int n = nums.size();
        vector<int> averages(n, -1); 
        if (2 * k + 1 > n) {
            return averages;
        }
 
        long long windowSum = 0;
        for (int i = 0; i < (2 * k + 1); ++i) {
            windowSum += nums[i];
        }
        averages[k] = windowSum / (2 * k + 1);
 
        for (int i = (2 * k + 1); i < n; ++i) {
           
            windowSum = windowSum - nums[i - (2 * k + 1)] + nums[i];
            averages[i - k] = windowSum / (2 * k + 1);
        }

        return averages;
    }
};