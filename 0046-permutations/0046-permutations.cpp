class Solution {
public:
    int fac(int n)
    {
        if(n==1 ||n==0)
            return 1;
        return n*fac(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=fac(nums.size());
        
        while(n--)
        {
            ans.push_back(nums);
            next_permutation(nums.begin(), nums.end());
        }
        return ans;
       
    }
};