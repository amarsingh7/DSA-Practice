class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2 !=0 && high%2 !=0)
        {
            return 1+ (high-low)/2.0; 
        }
        if(low%2 !=0 && high%2==0 || low%2 ==0 && high%2 !=0)
        {
            return ceil((high-low)/2.0);
        }
        else
            return (high-low)/2.0;
    }
};