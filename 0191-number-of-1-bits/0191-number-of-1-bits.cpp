class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        int rem;
        while(n>0)
        {
            if((n&1)> 0)
              ans++;
            n=n/2;
        }
        return ans;
    }
};