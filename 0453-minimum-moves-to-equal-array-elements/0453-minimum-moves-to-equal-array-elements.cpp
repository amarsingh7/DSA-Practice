class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int sum= accumulate(nums.begin(), nums.end(), 0L);
        int small= *min_element(nums.begin(), nums.end());
        
        return sum- nums.size()*small;
    }
};