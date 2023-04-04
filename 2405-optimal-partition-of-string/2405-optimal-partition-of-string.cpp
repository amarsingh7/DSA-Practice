class Solution {
public:
    int partitionString(string s) {
        int n= s.size();
        
        int ans=1;
        set<char> st;
        
        for(auto x:s)
        {
            if(st.find(x) !=st.end())
            {
                st.clear();
                ans++;
            }
            st.insert(x);
            
        }
        return ans;
    }
};