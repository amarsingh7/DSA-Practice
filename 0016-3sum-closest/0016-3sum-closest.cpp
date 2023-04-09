class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res= nums[0]+nums[1]+ nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-1; i++)
        {
            int p1= i+1;
            int p2= nums.size()-1;
            
            while(p1<p2)
            {
                int csum= nums[i]+ nums[p1]+ nums[p2];
                if(csum > target)
                    p2 -= 1;
                else
                    p1 += 1;
                if(abs(csum-target) < abs(res-target))
                    res= csum;
                
            }
        }
        return res;
    }
};