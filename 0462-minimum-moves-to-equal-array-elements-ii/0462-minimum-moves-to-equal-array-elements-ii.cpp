class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int avg=0;
        if(n%2 !=0)
            avg= nums[(n-1)/2];
        if(n%2 ==0)
            avg= (nums[n/2]+ nums[(n-2)/2])/2;
        for(int i=0; i<n; i++)
            nums[i]= abs(nums[i]- avg);
        
        return accumulate(nums.begin(), nums.end(), 0L);
    }
};