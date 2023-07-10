class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod=nums[0];
        int curmin= nums[0];
        int curmax= nums[0];
         
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]<0)
                swap(curmin, curmax);
            curmin= min(nums[i], curmin*nums[i]);
            curmax= max(nums[i], curmax*nums[i]);
            
            maxprod= max(maxprod, curmax);
        }
        return maxprod;
    }
};