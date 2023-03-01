class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n= nums.size();
        int index=0;
        for(auto &i:nums)
        {
            if(i<0)
                nums[index++]= -1;
            else if(i>0)
                nums[index++]= 1;
            else
                nums[index++]= 0;
        }
        int prod=1;
        for(int i=0; i<n; i++)
        {
            prod= prod*nums[i];
        }
        return prod;
    }
};