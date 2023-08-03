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
        
//         vector<int> singleNumber(vector<int> &nums) {
// 	int firstXorSec = 0, mask = 1, first = 0;
// 	// get xor of first and sec
// 	for (auto &num: nums) firstXorSec ^= num;
// 	// get rightmost set bit in above xor
// 	while (not (firstXorSec & mask)) mask <<= 1;
// 	// get first distinct number
// 	for (auto &num: nums)
// 		if (num & mask) first ^= num;
// 	// return ans
// 	return {first, firstXorSec ^ first};
// }
        
    }
};