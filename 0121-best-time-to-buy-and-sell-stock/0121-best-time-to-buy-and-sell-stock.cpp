class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int mp =INT_MAX;
        int ans=0;
        for(int i=0; i< n; i++)
        {
            mp = min(mp, prices[i]);
            ans = max(ans, prices[i] - mp);
        }
        return ans;
    }
};