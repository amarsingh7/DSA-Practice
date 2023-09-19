class Solution {
public:
    
    int totalSteps(vector<int>& nums) {
        int n= nums.size();
        int res=0;
        stack<int> st;
        vector<int> vec(n);
        
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() and nums[i]>nums[st.top()])
            {
                vec[i]= max(vec[i]+1, vec[st.top()]);
                st.pop();
            }
            st.push(i);
            res= max(res, vec[i]);
        }
        return res;
        
    }
};