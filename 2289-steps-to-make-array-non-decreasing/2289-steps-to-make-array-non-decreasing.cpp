class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        stack<int> st; // Create a stack to keep track of indices
        vector<int> vec(n); // Create a vector to store the number of steps for each element
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                // While the stack is not empty and the current 
                // element is greater than the element at top of the stack
                // This loop processes elements in decreasing order of value
                // Each element is compared to the elements in the stack to calculate the number of steps required to sort it
                // This loop effectively finds the number of larger elements to the right of the current element
                // The number of steps for the current element is the maximum between its current value and the value of the element at the top of the stack plus 1
                vec[i] = max(vec[i] + 1, vec[st.top()]);
                st.pop(); // Remove the element from the stack as it is no longer needed for this calculation
            }
            st.push(i); // Push the current index onto the stack
            res = max(res, vec[i]); // Update the maximum number of steps
        }
        return res; // Return the maximum number of steps needed to sort the array
    }
};
