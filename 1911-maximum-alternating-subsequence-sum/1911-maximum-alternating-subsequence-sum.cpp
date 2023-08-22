class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        
        long long even=0, odd=0;
        for(auto x:nums)
        {
            even= max(even, odd+x);
            odd= even-x;
        }
        return even;
    }
};