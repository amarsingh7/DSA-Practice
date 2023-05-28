class Solution {
public:
    int sum(vector<int> weights)
    {
        int res=0;
        for(auto x:weights)
            res+= x;
        return res;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        //int left= *max_element(weights.begin(), weights.end());
//         int right= 25000000;
//         int left=0;
//         for (int w: weights)
//             left = max(left, w);
//         while(left< right)
//         {
//             int ans=0;
//             int day=1;
//             int mid= (left+right)/2;
//             for(int i=0; i<weights.size() and day<=days; i++)
//             {
//                 ans+= weights[i];
//                 if(ans+ weights[i] >mid)
//                     ans=0, day++;
//             }
//             if(day> days)
//                 left= mid+1;
//             else
//                 right= mid;
                
//         }
//         return left;
//     }
    
    int left = 0, right = 25000000;
        for (int w: weights)
            left = max(left, w);
        while (left < right) {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int i = 1; i < weights.size() && need <= D; i++){
                cur += weights[i-1]; if (cur + weights[i] > mid)
                    cur = 0, need++;}
            if (need > D) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};