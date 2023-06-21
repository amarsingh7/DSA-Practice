
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<std::pair<int, int>> numsAndCost(n);
        for (int i = 0; i < n; ++i) {
            numsAndCost[i] = {nums[i], cost[i]};
        }
        sort(numsAndCost.begin(), numsAndCost.end());

        vector<long long> prefixCost(n);
        prefixCost[0] = numsAndCost[0].second;
        for (int i = 1; i < n; ++i)
            prefixCost[i] = numsAndCost[i].second + prefixCost[i - 1];

        long long totalCost = 0;
        for (int i = 1; i < n; ++i)
            totalCost += 1LL * numsAndCost[i].second * (numsAndCost[i].first - numsAndCost[0].first);
        long long answer = totalCost;

        for (int i = 1; i < n; ++i) {
            int gap = numsAndCost[i].first - numsAndCost[i - 1].first;
            totalCost += 1LL * prefixCost[i - 1] * gap;
            totalCost -= 1LL * (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
            answer = std::min(answer, totalCost);
        }

        return answer;
    }
};
