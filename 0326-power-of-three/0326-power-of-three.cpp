class Solution {
public:
    bool isPowerOfThree(int n) {
        // as for the int limit 2^31= 2147483647 (max_int)
        // similarly on powers of 3 the limit is 3^(log3(max_int))= 19.5
        // so 3^19= 1162261467 is limit on powers of 3
        if(n<=0)
            return false;
        while(n!=1){
            int r=n%3; // r: remainder
            n=n/3;
            if(r!=0) return false;
        }
        return true;
    }
};