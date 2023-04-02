class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size();
        int m= potions.size();
        
        sort(potions.begin(), potions.end());
        vector<int> v;
        
        int maxp= potions[m-1];
        
        for(auto s:spells)
        {
            long long minp= ceil((1.0*success)/s);
            if(minp >maxp)
            {
                v.push_back(0);
                continue;
            }
            auto index= lower_bound(potions.begin(), potions.end(), minp) - potions.begin();
            
            v.push_back(m-index);
        }
        return v;
    }
};