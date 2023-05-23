class Solution {
public:
    bool isPerfectSquare(int x) {
        if(x==0 || x==1)
            return true;
        long long start=0, end= x;
        while(start<=end)
        {
            long long mid= (start+end)/2;
            if(mid*mid==x)
                return true;
            else if(mid*mid <x)
                start= mid+1;
            else
                end= mid-1;
        }
        return false;
    }
};