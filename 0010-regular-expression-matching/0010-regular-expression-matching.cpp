class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p)
            return true;
        return isMatch(0, 0, s, p);
    }

    bool isMatch(int i, int j, string& s, string& p) {
        int sn = s.size();
        int pn = p.size();

        if (j == pn)
            return i == sn;

        if (j + 1 < pn && p[j + 1] == '*') {
            if (isMatch(i, j + 2, s, p))
                return true;
            if (i < sn && (s[i] == p[j] || p[j] == '.')) {
                return isMatch(i + 1, j, s, p);
            }
        }
        
        if (i < sn && (p[j] == '.' || s[i] == p[j]))
            return isMatch(i + 1, j + 1, s, p);

        return false;
    }
};
