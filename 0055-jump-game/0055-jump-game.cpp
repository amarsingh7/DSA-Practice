class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int reach=0, i;
        for(i=0; i<n and i<=reach; i++)
        {
            reach = max(i+nums[i], reach);
        }
        if(i==n)
            return true;
        return false;
    }
};