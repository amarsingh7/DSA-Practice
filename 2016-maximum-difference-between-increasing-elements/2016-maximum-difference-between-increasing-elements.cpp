class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n= nums.size();
        int maxdif= nums[1]- nums[0];
        
        int minele= nums[0];
        
        for(int i=1; i<n; i++)
        {
            if(nums[i]- minele >maxdif)
                maxdif= nums[i]- minele;
            if(nums[i] <minele)
                minele= nums[i];
        }
        return maxdif<=0? -1: maxdif;
    }
};