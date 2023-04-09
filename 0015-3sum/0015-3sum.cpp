class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int res= nums[0]+ nums[1]+ nums[nums.size()-1];
        
        for(int i=0; i<nums.size(); i++)
        {
            int p1= i+1;
            int p2= nums.size()-1;
            
            if(nums[i]>0)
                break;
            if(i>0 and nums[i]==nums[i-1])
                continue;
            
            int csum=0;
            while(p1<p2)
            {
                int csum= nums[i]+nums[p1]+nums[p2];
                if(csum>0)
                    p2 -=1;
                else if(csum<0)
                    p1 +=1;
                else{
                    ans.push_back({nums[i], nums[p1], nums[p2]});
                    int lastl= nums[p1];
                    int high= nums[p2];
                    while(p1 < p2 && nums[p1] == lastl){  
                        p1++;
                    }
                    while(p1 < p2 && nums[p2] == high){  
                        p2--;
                    }
                    
                }
          
                    
            }
        }
        return ans;
    }
};