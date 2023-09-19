class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int xdif= abs(sx-fx);
        int ydif= abs(sy-fy);
         
        if((xdif==0) and (ydif==0) and (t==1))
            return false;
        
        return (max(xdif, ydif) <=t);
    }
};