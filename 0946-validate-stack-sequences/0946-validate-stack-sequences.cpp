class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {

            int n = pushed.size();
            
            stack<int> st;
            int ans=0;
            
            for(auto i:pushed)
            {
                st.push(i);
                while(!st.empty() and ans<n and st.top()==popped[ans])
                {
                    st.pop();
                    ans++;
                }
            }
            return ans==n;
        }
};