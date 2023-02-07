class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n=nums.size();
        int start = -1, firstneg = -2, len = 0, neg = 0;
        for (int i = 0; i < n; i++) 
        {
            if (nums[i] == 0) 
            {  
                neg = 0;
                start = i;
                firstneg = -2;
            } 
            else 
            {
                if (nums[i] < 0) neg++; 
                if (neg == 1 && firstneg == -2) firstneg = i;   
                if (neg % 2 == 0) len = max(len, i - start); 
                else len = max(len, i - firstneg); 
            }
        }
        return len;
    }
};