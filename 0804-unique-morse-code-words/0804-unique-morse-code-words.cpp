class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int ans=0;
        vector<string> d = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> s;
        for (auto w : words) {
            string code;
            for (auto c : w) code += d[c - 'a'];
            s.insert(code);
        }
        return s.size();
    }
};