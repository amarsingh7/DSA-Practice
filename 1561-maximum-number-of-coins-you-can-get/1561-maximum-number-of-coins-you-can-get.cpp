class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n= piles.size();
        
        sort(piles.begin(), piles.end());
        int x= n/3;
        int ans=0;
        
        for(int i= n-2; i>=x; i-=2)
        {
            ans+= piles[i];
        }
        
        return ans;
        
    }
};