class Solution {
public:
    
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Store indices of potential maximum elements
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove elements that are smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);  // Push the current index

        // Start recording maximum once the window is complete
        if (i >= k - 1)
            result.push_back(nums[dq.front()]);
    }

    return result;
}
};