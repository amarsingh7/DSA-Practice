class Solution {
public:
    int rsum(vector<int> &weights)
    {
        int sum=0;
        for(int i=0; i<weights.size(); i++)
        {
            sum+= weights[i];
        }
        return sum;
    }
    bool feasible(vector<int> &weights, int c, int days)
    {
        int dn=1, cl= 0;
        for(auto wt:weights)
        {
            cl+= wt;
            if(cl> c)
            {
                dn++;
                cl= wt;
            }
        }
          return dn<= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left= *max_element(weights.begin(), weights.end());
        int right= rsum(weights);
        int ans=0;
        
        while(left< right)
        {
            int mid= (left+right)/2;
            if(feasible(weights, mid, days))
                right= mid;
            else
                left= mid+1;
                
        }
        return left;
    }
};