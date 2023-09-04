class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size(), res = N + 1;
        deque<int> d;
        vector<long long> prefixSum(N + 1, 0);

        for (int i = 0; i < N; i++) {
            prefixSum[i + 1] = prefixSum[i] + A[i];
        }

        for (int i = 0; i <= N; i++) {
            while (!d.empty() && prefixSum[i] - prefixSum[d.front()] >= K) {
                res = min(res, i - d.front());
                d.pop_front();
            }

            while (!d.empty() && prefixSum[i] <= prefixSum[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);
        }

        return res <= N ? res : -1;
    }
};
