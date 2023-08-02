class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==INT_MIN)
            return false;
        return bitset<32>(n).count() ==1? true:false;
    }
};