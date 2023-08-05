class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
    int n = nums.size();
    
    // Base case: If the vector contains only one element, no swaps needed, return 0 seconds
    if (n == 1)
        return 0;
    
    // Create a set to check if all elements are the same in the vector
    set<int> st(nums.begin(), nums.end());
    
    // If all elements are the same, return 0 seconds as no swaps needed
    if (n > 1 && st.size() == 1)
        return 0;

    int ans = INT_MAX;
    unordered_map<int, int> lastSeen, maxDiff;

    // Loop through the vector and calculate the maximum difference between current index and last seen index for each element
    for (int i = 0; i < n; ++i) {
        if (lastSeen.find(nums[i]) != lastSeen.end()) {
            maxDiff[nums[i]] = max(maxDiff[nums[i]], i - lastSeen[nums[i]] - 1);
        }
        lastSeen[nums[i]] = i;
    }

    // Handle the case of rotation by repeating the process again
    for (int i = 0; i < n; ++i) {
        // To handle rotation, calculate maxDiff by considering elements at the beginning of the array after rotation
        maxDiff[nums[i]] = max(maxDiff[nums[i]], (i - lastSeen[nums[i]] - 1 + n) % n);
        lastSeen[nums[i]] = i;
    }

    // Find the minimum value from maxDiff map which represents the minimum number of swaps required
    for (auto [k, v] : maxDiff) {
        ans = min(ans, v);
    }

    // Return half of the minimum swaps as each swap takes two seconds
    return (ans + 1) / 2;
}

};