class Solution {
public:
    bool isPowerOfFour(int n) {
        // int limit on powers of 4.
        // 14^(log4(2147483647))= 14^(15.5)= 2147483648
        if(n<=0)
            return 0;
        while(n!=1)
        {
            int r= n%4; // r: remainder
            n= n/4;
            if(r!=0) 
                return false;
        }
        return true;
    }
};