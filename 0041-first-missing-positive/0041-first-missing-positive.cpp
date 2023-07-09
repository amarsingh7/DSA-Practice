class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool> hash(n+1, 0);
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0 and nums[i]<=n)
            hash[nums[i]]= 1;
        }
        for(int i=1; i<=n; i++)
            if(!hash[i])
                return i;
        
        return n+1;
    }
};