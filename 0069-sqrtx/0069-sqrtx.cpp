class Solution {
public:
    int mySqrt(int x) {
        if(x==0 or x==1)
            return x;
        int i=0;
        int j= x;
        while(i<=j)
        {
            long long mid= i+(-i+j)/2;
            if((long long)mid*mid==x)
                return mid;
            else if(mid*mid <x)
                i= mid+1;
            else
                j= mid-1;
        }
        return j;
    }
};