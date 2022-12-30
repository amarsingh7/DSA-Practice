class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxim = 0;
        int sum = 0;
        for(int i = 0 ; i< nums.size(); i++){
            sum += nums[i];
            if(nums[i] == 0)    // reset sum to zero when encounters zeros
                sum = 0;
            else                // keep update max
                maxim = max(maxim, sum);
        }
        return maxim;
    }
};