class Solution {
public:
    bool isHappy(int n) {
        int ans=0;
        while(n>6)
        {
        int next = 0;
        while(n)
        {
            next+= (n%10)*(n%10); 
            n/=10;
        }
            n = next;
        }
    return n==1;
        
    }
};