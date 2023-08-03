class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorfs=0, mask=1, first=0;
        for(auto &x:nums)
            xorfs ^= x;
        
        while(!(xorfs & mask))
            mask <<= 1;
        
        for(auto &x:nums)
        {
            if(x & mask)
                first ^= x;
        }
        return {first, xorfs^first};
        
    }
};