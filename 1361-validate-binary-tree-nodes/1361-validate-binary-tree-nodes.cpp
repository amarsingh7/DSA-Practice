class Solution {
public:
    int rootfind(int n, vector<int> &left, vector<int> &right)
    {
        unordered_set<int> st;
        st.insert(left.begin(), left.end());
        st.insert(right.begin(), right.end());
        
        for(int i=0; i<n; i++)
        {
            if(st.find(i)==st.end())
                return i;
        }
        return -1;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftc, vector<int>& rightc) {
        
        int root= rootfind(n, leftc, rightc);
        if(root== -1)
            return false;
        
        stack<int> st;
        unordered_set<int> seen;
        
        seen.insert(root);
        st.push(root);
        
        while(!st.empty())
        {
            int val= st.top();
            st.pop();
            
            auto children= {leftc[val], rightc[val]};
            for(auto c:children)
            {
                if(c != -1)
                {
                    if(seen.find(c) != seen.end())
                        return false;
                    st.push(c);
                    seen.insert(c);
                }
            }
        }
        return seen.size()==n;
    }
};