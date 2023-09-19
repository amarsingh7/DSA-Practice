class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n= nums.size();
        if((n==1) and (k%2==0))
            return nums[0];
        if((n==1 ) and (k%2 !=0))
            return -1;
        if((n>1) and (k==1))
            return nums[1]; 
            
        if(n<k)
            return *max_element(nums.begin(), nums.end());
        int res=0;
        for(int i=0; i<k-1; i++) 
            res= max(res, nums[i]);
        if(nums[k]>res)
            return nums[k];
        return res;
        
    }
};