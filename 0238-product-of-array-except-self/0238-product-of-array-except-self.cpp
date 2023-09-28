class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) { 
        int prod=1;;
        int n= nums.size();
        vector<int> pvec(n, 1), svec(n, 1) ;
        
        pvec[0]= 1;
        svec[n-1]= 1;
        
        for(int i=1; i<n; i++)
        {
            pvec[i]= pvec[i-1]*nums[i-1];
        }
        for(int i=n-2; i>=0; i--)
        {
            svec[i]= svec[i+1]*nums[i+1];
        }
        
        vector<int> ans(n);
        
        for(int i=0; i<n; i++)
        {
            ans[i]= pvec[i]*svec[i];
        }
        return ans;
        
    }
};