class Solution {
public:
    string convertToTitle(int colnum) {
        string res;
        
        while(colnum>0)
        {
            colnum--;
            res+= (char)((colnum%26) +'A');
            colnum/= 26;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};