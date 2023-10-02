class Solution {
public:
    int longestValidParentheses(string s) {
        int n= s.size();
        int ans=0, res=0;
        stack<int> st;
        st.push(-1);    
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else
                    res= max(res, i-st.top());
            } 
        }
        return res;
    }
};