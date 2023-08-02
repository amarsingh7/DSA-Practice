class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)  // any negative n can't be achieved by 2's power. 
            return false;
        return bitset<32>(n).count() ==1? true:false;
    }
};