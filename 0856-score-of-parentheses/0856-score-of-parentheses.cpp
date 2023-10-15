class Solution {
public:
    int scoreOfParentheses(string s) {
        int n= s.size();
        if(n==2)
            return 1;
        
        char prev= '(';
        int depth=0, ans=0;
        
        for(auto c:s)
        {
            if(c=='(')
                depth++;
            else
            {
                depth--;
                if(prev=='(')
                    ans+= pow(2, depth) ;
            }
            prev= c;
        }
        return ans;
    }
};