class Solution {
public:
    int scoreOfParentheses(string s) {
        int n= s.size();
        if(n==2)
            return 1;
        stack<int> st;
        int ind=0, ans=0;
        
        for(auto c:s)
        {
            if(c=='(')  // found open aprentheses, calculation starts from here
            {
                st.push(ind);
                ind=0;
            }   
            else    // found closing parentheses, process them  
            {
                ind= st.top()+ max(2*ind, 1);
                st.pop();
                    
            }
        }
        return ind;
    }
};