class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int cnt=0;
        // for(int i=1; i<nums.size(); i++)
        // {
        //     if(nums[i]==nums[i-1]) cnt++;
        //     else nums[i-cnt]= nums[i];
        // }
        // return nums.size()- cnt;
        int ii=1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] != nums[i])
            {
                nums[ii]= nums[i];
                ii++;
            }
                
        }
        return ii;
    }
};