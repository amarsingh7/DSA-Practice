class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int used=0;
        int j=0;
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            while((used & nums[i]) !=0) 
                used ^= nums[j++];  // exclude from the window
            used |= nums[i];        // include in the window
            ans= max(ans, i-j+1);
        }
        return ans;
    }
};