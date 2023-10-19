class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ss= s.size();
        int ts= t.size();
        
        stack<char> st1, st2;
        
        for(int i=0; i<ss; i++)
        {
            if(s[i] !='#')
                st1.push(s[i]);
            else if(!st1.empty())
                st1.pop();
        }
        for(int i=0; i<ts; i++)
        {
            if(t[i] !='#')
                st2.push(t[i]);
            else if(!st2.empty())
                st2.pop();
        }
        return st1==st2;
    }
};