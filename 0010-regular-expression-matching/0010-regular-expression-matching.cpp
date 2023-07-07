class Solution {
public:
    bool isMatch(string s, string p) {
        if (s == p)
            return true; 
        vector<vector<char>> memo(s.size() +1, vector<char>(p.size(), -1));
        return isMatch(0, 0, s, p, memo);
    }

    bool isMatch(int i, int j, string& s, string& p, vector< vector<char>> &memo) {
        int sn = s.size();
        int pn = p.size();

        if (j == pn)
            return i == sn;

        if (j + 1 < pn && p[j + 1] == '*') {
            if (isMatch(i, j + 2, s, p, memo))
                return true;
            if (i < sn && (s[i] == p[j] || p[j] == '.')) {
                return memo[i][j]=isMatch(i + 1, j, s, p, memo);
            }
        }
        
        if (i < sn && (p[j] == '.' || s[i] == p[j]))
            return memo[i][j]=isMatch(i + 1, j + 1, s, p, memo);

        return memo[i][j]=0;
    }
};
