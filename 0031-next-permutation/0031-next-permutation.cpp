class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) { 
            // checking the first element (nums[k]) that is less than its next element. 
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) // this means the nums is completely in descending order.
    	    reverse(nums.begin(), nums.end());
    
        else 
        {   // checking the least element just greater than nums[k] in right of it.
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k])
                    break;
        } 
    	swap(nums[k], nums[l]);
    	reverse(nums.begin() + k + 1, nums.end());  
            // necessary to get the next lexicographically greater permutation.
        }
    }
};