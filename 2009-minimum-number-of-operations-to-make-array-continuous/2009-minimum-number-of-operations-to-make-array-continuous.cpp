class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        set<int> st;
        
        vector<int> temp;
        for(auto x:nums)
            st.insert(x);
        
        for(auto x:st)
            temp.push_back(x);
        
        int left= 0, right=0;
        int ans= INT_MAX;
        for(int i=0; i<temp.size(); i++)
        {
            left= temp[i];
            right= left+ n-1;
            
            int j= upper_bound(temp.begin(), temp.end(), right)- temp.begin();
            int count= j-i;
            ans= min(ans, n-count);
        }
        
        return ans;
    }
};