class Solution {
public:
    bool checkValidString(string s) {
       int op = 0, cl = 0;
       for (char c: s) 
       {
           if(c == '(')
                op += 1;
           else
               op -= 1;
           if(c != ')')
               cl += 1;
           else
               cl -= 1;
           if (cl < 0) 
                break;
           op = max(op, 0);
       }
       return op == 0 and s.size() !=0;
    }
};