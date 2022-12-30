class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0, count=0;
        int n= nums.size();
        sum= n*(n+1)*(0.5);
        for(int i=0; i<n; i++)
        {
            count+= nums[i];
        }
        return sum- count;
    }
};