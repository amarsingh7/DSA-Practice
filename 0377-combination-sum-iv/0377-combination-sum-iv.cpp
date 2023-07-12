class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    vector<long long> comb(target + 1);
    comb[0] = 1;
    int MOD= 1e9 +7;
        
    for (int i = 1; i < comb.size(); i++) 
    {
        for (int j = 0; j < nums.size(); j++) 
        {
            if (i - nums[j] >= 0) 
                comb[i] += (1LL)*(comb[i - nums[j]])%MOD;
        }
    }
    return comb[target];
    }
};