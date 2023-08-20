class Solution {
public:
    
    int solve(int i, int m, vector<vector<int>> &offers, vector<int>&dp)
    {
        if(i>=m)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        vector<int> temp;
        temp.push_back(offers[i][1]); temp.push_back(INT_MAX);
        temp.push_back(INT_MAX);
        
        int nextind= upper_bound(offers.begin(), offers.end(), temp)- offers.begin();
        int take= solve(nextind, m, offers, dp)+ offers[i][2];
        int notake= solve(i+1, m, offers, dp);
            
        return dp[i]= max(take, notake);
    }
    
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m= offers.size();
        vector<int> dp(m+1, -1);
        sort(offers.begin(), offers.end());
        return solve(0, m, offers, dp);
    }
};