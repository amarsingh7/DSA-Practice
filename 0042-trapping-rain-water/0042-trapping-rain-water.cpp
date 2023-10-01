class Solution {
public:
    int trap(vector<int>& ht) {
        int ans=0;
        int n= ht.size();
        vector<int> pvec(n), svec(n);   
        pvec[0]= ht[0];
        svec[n-1]= ht[n-1];
        
        // finding prefix max element seen so far at each index
        for(int i=1; i<n; i++)
        {
            pvec[i]= max(pvec[i-1], ht[i]);
        }
        // finding suffix max eleemnt so far at each index
        for(int i=n-2; i>=0; i--)
        {
            svec[i]= max(svec[i+1], ht[i]);
        }
        // amount of trapped rain calculation.
        for(int i=0; i<n; i++)
        {
            ans+= min(pvec[i], svec[i])- ht[i];
        }
        
        return ans;
    }
};