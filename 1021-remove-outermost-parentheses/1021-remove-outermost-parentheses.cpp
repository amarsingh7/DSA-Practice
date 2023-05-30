class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int cnt=0;
        for(auto x:s)
        {
            if(x=='(' and cnt++ >0)
                ans+= x;
            if(x==')' and cnt-- >1)
                ans+= x;
        }
        return ans;
    }
};