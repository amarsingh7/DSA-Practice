class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n= heights.size();
        vector<int>ans(n, 0), st;
        
        int count=0; 
        for(int i=0; i<n; i++)
        {
            while(!st.empty() and heights[st.back()] <= heights[i])
            {
                ans[st.back()]++;
                st.pop_back();
            }
            if(!st.empty())
            {
                ans[st.back()]++; 
            }
            st.push_back(i);
        }
        return ans;
    }
};