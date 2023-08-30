class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))
            return 0;
        int n= nums.size();
        long long ans=0;
        for(int i=n-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
                continue;
            long long numele= ceil((nums[i] + nums[i+1]-1LL) / (nums[i+1]));
            
            ans+= numele-1;
            nums[i]= nums[i]/numele;
        }
        
        return ans;
    }
};