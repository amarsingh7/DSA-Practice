class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n= s.size();
        
        string res(n, '0');
        for(int i=0; i<n; i++)
        {
            res[indices[i]]= s[i];
        }
        return res;
    }
};