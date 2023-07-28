class Solution {
private:
    int maxdiff(vector<int> &nums, int left, int right, int n) {
        if (left == right) {
            return nums[left];
        }
        
        int scoreByLeft = nums[left] - maxdiff(nums, left + 1, right, n);
        int scoreByRight = nums[right] - maxdiff(nums, left, right - 1, n);
        
        return max(scoreByLeft, scoreByRight);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        return maxdiff(nums, 0, n-1, n) >=0;
        
    } 
};