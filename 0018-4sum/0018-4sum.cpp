class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=  nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            long long p3= target- nums[i];
            
            for(int j=i+1; j<n; j++)
            {
               long long p2= p3- nums[j];
                
               int front= j+1;
               int back= n-1;
               
                while(front<back)
                {
                    int sum2= nums[front]+nums[back];
                    
                    if(sum2<p2)
                       front++;
                    else if(sum2>p2)
                        back--;
                    else
                    {
                        ans.push_back({nums[i], nums[j],nums[front], nums[back]});
                        int lastl= nums[front];
                        int highh= nums[back];
                        
                        while(front<back and nums[front]==lastl)
                            front++;
                        while(front<back and nums[back]==highh)
                            back--;
                        
                    }
                        
                }
            }
            
        }
        sort(ans.begin(), ans.end());
ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};