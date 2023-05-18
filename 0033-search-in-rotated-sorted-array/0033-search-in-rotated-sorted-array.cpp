class Solution {
public:
    int pivotindex(vector<int> nums)
    {
        int start=0, end= nums.size()-1;
        int ans=0;
        while(start<end)
        {
            int mid= (start+end)/2;
            if(nums[start]<nums[end])
                return start;
            if(nums[mid] >= nums[start])
                start=mid+1;
            else
                end= mid;
        }
        return start;
    }
    
    int search(vector<int>& nums, int target) {
        int lo, hi;
        int n= nums.size();
        lo= pivotindex(nums);
        int rot=lo;
        lo=0; hi=n-1;
        while(lo<=hi)
        {
            int mid= (lo+hi)/2;
            int rmid= (mid+rot)%n;
            if(nums[rmid]== target)
                return rmid;
            if(nums[rmid]< target)
                lo= mid+1;
            else hi= mid-1;
        }
        return -1;
        
    }
};