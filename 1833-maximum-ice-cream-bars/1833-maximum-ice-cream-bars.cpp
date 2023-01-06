class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n= costs.size();
        int sum=0; int c=0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < n; ++i)
            if ((coins -= costs[i]) < 0)
                return i;
        return costs.size();
    }
};