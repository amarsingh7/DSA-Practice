class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<=n; i++)
        {
            if(find(nums.begin(), nums.end(), i) ==nums.end())
                ans=i;
        }
        return ans;
    }
};