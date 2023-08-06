class Solution {
public:
    unordered_set<string> st,vis;
    
    int countmin(string &s)
    {
        stack<int> st;
        
        for(char ch:s)
        {
            if(ch=='(')
                st.push(ch);
            else if(ch==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    st.push(ch);
            }
        }
        
        return st.size();
    }
    
    void removemin(string s,int c)
    {
        if(vis.find(s)!=vis.end())
            return;
            
        vis.insert(s);
        
        if(c==0)
        {
            st.insert(s);
            return;
        }
                
        int n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]==')')
                removemin(s.substr(0,i)+s.substr(i+1),c-1);
        }       
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> ans;
        int c=countmin(s);
        
        removemin(s,c);
        
        for(string str:st)
        {
            if(!countmin(str))
                ans.push_back(str);
        }
        
        return ans;
    }
};