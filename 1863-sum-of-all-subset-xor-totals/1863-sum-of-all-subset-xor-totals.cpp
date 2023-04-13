class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int n:nums)
            sum|=n;
        return sum*pow(2, n-1);
    }
};