class Solution {
public:
    int maxProfit(vector<int>& prices) {
    
    int firstbuy= INT_MIN, secbuy= INT_MIN;
    int firstsell= 0, secsell= 0;
    
    for(int i=0; i<prices.size(); i++)
    {
        firstbuy= max(firstbuy, -prices[i]);
        firstsell= max(firstsell, prices[i]+ firstbuy);
        secbuy= max(secbuy, firstsell- prices[i]);
        secsell= max(secsell, secbuy+ prices[i]);
        
    }
    return secsell;
    }
};