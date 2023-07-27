class Solution {
public:
    int dp[302][302];
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=n; i++)
        {
            for(int start=1; start<=n-i+1; start++)
            {
                int end= start+i-1;
                for(int x=start; x<=end; x++)
                    dp[start][end]= max(dp[start][end], dp[start][x-1]+nums[start-1]*nums[x]*nums[end+1]+ dp[x+1][end]);
            }
        }
        return dp[1][n];
    }
};