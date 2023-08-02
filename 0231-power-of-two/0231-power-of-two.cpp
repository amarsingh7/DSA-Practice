class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)  // -2147483648 
            return false;
        return bitset<32>(n).count() ==1? true:false;
    }
};