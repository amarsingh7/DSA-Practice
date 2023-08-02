class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i = 0; i < 32; i++)
        {
            // In each iteration, ans l-shifts to make room for adding 
            // the rightmost bit of n
            ans = (ans <<1) + n % 2;
            n = n>>1; 
            // the processed rightmost bit is removed by r-shift, and new
            // unprocessed bit comes from left.
        }
        return ans;               
    }
};