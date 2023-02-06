class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int m=0, p=1;
        for(int i=0; i<n; i++)
        {
            ans[m]= nums[i];
            m=m+2;
        }
        for(int j=n; j<2*n; j++)
        {
            ans[p]= nums[j];
            p=p+2;
        }
        return ans;
    }
};