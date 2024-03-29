class Solution {
public:
    int minAddToMakeValid(string s) {
        int n= s.size();
        stack<char> st;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')   st.push(s[i]);
            else if(!st.empty() and (st.top()=='(') and (s[i]==')'))
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};