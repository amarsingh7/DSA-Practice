class Solution {
public:
    // int fac(int n)
    // {
    //     if(n==1 ||n==0)
    //         return 1;
    //     return n*fac(n-1);
    // }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n= nums.size();
        vector<int> fac(n+1);
        fac[0]= 1;
        for(int i=1; i<=n; i++)
            fac[i]= fac[i-1]*i;
        
        while(fac[n]--)
        {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
       
    }
};