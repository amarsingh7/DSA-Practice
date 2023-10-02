class Solution {
public:
    int longestValidParentheses(string s) {
        int n= s.size();
        int ans=0, res=0;
        stack<int> st;
        st.push(-1);  // You can imagine there is a ) at index -1 position
        // i.e. s[-1] = ')'  
        
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                // if there is a match (i.e. "()"), then we can pop the stack
                // and update the max length by (i - indices.top())
                // (because the string in (indices.top(), i] is a valid parenthese)
                // else if there isn't a match (i.e. "))"), then we can substitute
                // the top of the stack by the latest one
                // To sum up, no matter "()" or "))", we all need to pop the stack
                st.pop();   
                // if the stack is empty, it means a "))" occurs
                
                if(st.empty())
                    st.push(i); 
                // a "()" occurs
                else
                    res= max(res, i-st.top());
            } 
        }
        return res;
    }
};
