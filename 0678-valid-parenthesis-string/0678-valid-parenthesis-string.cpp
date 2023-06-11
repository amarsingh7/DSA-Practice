class Solution {
public:
    bool checkValidString(string s) {
       int lo = 0, hi = 0;
       for (char c: s) 
       {
           if(c == '(')
                lo += 1;
           else
               lo -= 1;
           if(c != ')')
               hi += 1;
           else
               hi -= 1;
           if (hi < 0) 
                break;
           lo = max(lo, 0);
       }
       return lo == 0;
    }
};