class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n= nums.size();
        map<int, int> mp;
        int left=0;
        long long res=0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            long long tar= nums[i];
            res+= tar;
            
            if((i-left+1)* tar- res >k)
            {
                res-= nums[left];
                left++;
            }
        }
        
        return n- left;
    }
};