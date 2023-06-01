class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mps(256, -1), mpt(256, -1);
        for(int i=0; i<s.size(); i++)
        {
            if(mps[s[i]] !=mpt[t[i]])
                return false;
            mps[s[i]]= mpt[t[i]]= i;
        }
        return true;
    }
};