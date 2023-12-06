class Solution {
public:
    int totalMoney(int n) {
        int mon=0;
        if(n<=7)
            return n*(n+1)/2;
        mon= n/7;
        int cmod= n%7;
        
        int pw= mon*28 + 7*((mon-1)* mon/2);
        int lw= cmod* (cmod+1)/2 + mon*cmod;
        
        return pw+ lw;
    }
};