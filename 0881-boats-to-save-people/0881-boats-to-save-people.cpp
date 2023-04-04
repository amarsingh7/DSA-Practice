class Solution {
public:
    int numRescueBoats(vector<int>& pp, int limit) {
        sort(pp.begin(), pp.end());
        int n= pp.size();
        if(n==1)
            return 1;
        int ans=0;
        int i=0; int j= n-1;
        
        while(i<=j)
        {
            ans++;
            if(pp[i]+pp[j] <= limit)
            {
                i++; j--;
            }
            else
                j--;
        }
        
        return ans;
        
    }
};