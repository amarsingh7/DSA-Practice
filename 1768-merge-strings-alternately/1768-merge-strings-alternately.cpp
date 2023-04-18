class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        for (int i = 0; i < w1.size() || i < w2.size(); ++i) {
            if (i < w1.size())
                res.push_back(w1[i]);
            if (i < w2.size())
                res.push_back(w2[i]);
        }
        return res;
    }
};