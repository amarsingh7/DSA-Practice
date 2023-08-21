class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.size();
        
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1) 
            return true;
        return false;
    }
};