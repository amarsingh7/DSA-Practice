class Solution {
public:
    int sum(vector<int> weights)
    {
        int res=0;
        for(auto x:weights)
            res+= x;
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {

    int left = *max_element(weights.begin(), weights.end());
    int right = sum(weights);
        while (left < right) 
        {
            int mid = (left + right) / 2;
            int need = 1, cur = 0;
            for (int i = 1; i < weights.size() && need <= days; i++)
            {
                cur += weights[i-1]; 
                if (cur + weights[i] > mid)
                    cur = 0, need++;
            }
            if (need > days) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};