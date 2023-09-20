class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        // Handle the edge case of a single element not equal to x
        if (n == 1 && nums[0] != x)
            return -1;
        
        vector<int> prefsum;
        prefsum.push_back(0);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefsum.push_back(sum);
        }

        // If sum of all elements is less than x, no soln exists
        if (sum < x)
            return -1;

        // If sum of all elements == x, return length of nums
        if (sum == x)
            return n;

        // Calculate suffix sum and corresponding indexes for each prefix sum
        unordered_map<int, int> sufsum;

        for (int i = 0; i < n; i++) {
            sufsum[sum] = i;  
            // Store the current index for the current sum
            sum -= nums[i];   
            // Subtract current element to move to the next sum
        }

        //to handle case where sum of all elements is target (x),
        // we set the suffix sum for 0 to n (i.e., the entire array length).
        sufsum[0] = n;

        int ans = INT_MAX;

        int i = 0;
        while (prefsum[i] <= x) {
            int target = x - prefsum[i];

            if (sufsum[target])
                ans = min(ans, i + n - sufsum[target]);

            i++;
        }

        // If no valid answer is found, return -1
        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};
