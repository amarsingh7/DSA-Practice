class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        for(int i = 0; i < 32; i++)
        {
           //for inversing a decimal number, simply replace 2 by 10
            ans = (ans <<1) + n % 2;
            n = n>>1; // we can also do, n= n/2;
        }
        return ans;
    }
};