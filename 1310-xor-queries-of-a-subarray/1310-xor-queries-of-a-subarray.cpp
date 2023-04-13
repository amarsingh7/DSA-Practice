class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n= arr.size();
        int m= queries[0].size();
        
        vector<int> ans;
        
        for(int i=1; i<n; i++)
        {
            arr[i] ^= arr[i-1];
        }
        for(auto &q:queries)
        {
            ans.push_back(q[0]>0 ? arr[q[0]-1] ^ arr[q[1]] : arr[q[1]]);
        }
        return ans;
    }
};