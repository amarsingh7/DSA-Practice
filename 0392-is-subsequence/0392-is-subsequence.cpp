class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n= t.size(), m= s.size();
        int i=0;
        for(int j=0; j<n; j++)
        {
            if(s[i]== t[j])
                i++;
        }
        return i==m;
    }
};