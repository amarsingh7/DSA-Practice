class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans=0;
        int n= weights.size();
        vector<int> pairw(n-1, 0);
        
        for(int i=0; i<n-1; i++)
            pairw[i]= weights[i]+ weights[i+1];
        sort(pairw.begin(), pairw.end());
        
        for(int i=0; i<k-1; i++)
            ans+= pairw[n-2-i]- pairw[i];
        return ans;
    }
};