class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans=0, check= INT_MAX;
        
        for(auto x:nums)
        {
            check &= x;
            if(check==0)
                ans++, check= INT_MAX;
        }
        return max(1, ans);
    }
};

/*
We can split the array only if the score of all subarrays is zero(Eg-1).

If the score of the entire array is not zero but m, then the score of any subarray cannot be less than m. Therefore, any split will add at least m to the sum.

So, we count subarrays with the zero score.
*/