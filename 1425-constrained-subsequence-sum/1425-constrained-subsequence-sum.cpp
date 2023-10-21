class Solution {
public:
    
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
        
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        int ans= nums[0];
        
        for(int i=1; i<n; i++)
        {
            while(i- pq.top().second >k)
                pq.pop();
            int cur= nums[i] +max(pq.top().first, 0);
            ans= max(cur, ans);
            pq.push({cur, i});
            
        }
        return ans;
    }
};