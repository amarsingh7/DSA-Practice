class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        if(n == 1 && nums[0] != x) return -1;
        vector<int> prefsum;
        prefsum.push_back(0);

        int sum = 0;
        for(int i =0; i < n ;i++)
        {
            sum += nums[i];
            prefsum.push_back(sum);
        }
        if(sum < x) 
            return -1;
        if(sum == x) 
            return n;
        
        unordered_map<int,int> sufsum;

        for(int i = 0; i < n; i++)
        {
            sufsum[sum] = i;
            sum -= nums[i]; 
        }
        
        sufsum[0] = n; 

        int ans = INT_MAX;

        int i = 0;
        while(prefsum[i] <= x)
        {
            int target = x - prefsum[i];

            if(sufsum[target])
                ans = min(ans, i + n - sufsum[target]);
            
            i++;
        }
        
        if(ans == INT_MAX) return -1;
        return ans;
        
    }
};