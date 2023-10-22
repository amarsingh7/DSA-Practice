class Solution {
public:
    
    
    int maximumScore(vector<int>& nums, int k) {
        int n= nums.size();
        
        int i=k, j=k;
        int mini= nums[k];
        int ans= nums[k];
        
        while(i>0 || j <n-1)
        {
            if(i>0 and (nums[i-1]> nums[j+1]))
            {
                i--;
                mini= min(nums[i], mini);
            }
            else
            {
                j++;
                mini= min(mini, nums[j]);
            }
            
            ans= max(ans, mini*(j-i+1));
        }
        return ans;
    }
};