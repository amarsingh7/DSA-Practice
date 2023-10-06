class Solution {
public:
    int integerBreak(int n) {
        int ans=0;
        if(n<=3)
            return n-1;
        if(n==4)
            return n;
        if(n%3==1 and n>4)   // 
        {
            return (pow(3, (floor)(n/3) -1))*4;
        }
        if(n%3==2 and n>4)   // 8, 14, 
            return (int)(pow(3, n/3))*2;
        if(n%3==0)
            return pow(3, n/3);
        return 0;
    }
};