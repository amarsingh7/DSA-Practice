class Solution {
public:
    
    int asum(vector<int> nums, int mid)
    {
        int res=0;
        for(int i=0;  i<nums.size(); i++)
        {
            res+= ceil(1.0*nums[i]/mid);
        }
        return res;
    }
    int smallestDivisor(vector<int>& nums, int td) {
        int left=1, right= *max_element(nums.begin(), nums.end()) ;
        int sum=0;
        int res= -1;
        while(left<=right)
        {
            int mid= (left+ right)/2;
            sum= asum(nums, mid);
            if(sum<= td)
            {
                res= mid;
                right= mid-1;
            }
            else
                left= mid+1;
        }
        return res;
    }
};