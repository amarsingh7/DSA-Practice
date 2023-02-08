class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0 , low = 0 , high = 0 , n = nums.size() ;
        while(high < n - 1) 
        {
            int maxJump = 0 ;
            for(int i = low ; i <= high ; i++) 
                maxJump = max(maxJump , i + nums[i]) ;

            low = high + 1 ;
            high = maxJump ;
            cnt++ ;
        }
        return cnt ;
    }
};