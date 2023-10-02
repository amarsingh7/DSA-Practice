class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> indexes;
        int n = s.length();
        int num = words.size();
        int len = words[0].length();
        
        if (n == 0 || num == 0 || len == 0)
            return indexes;

        int wordSize = num * len;

        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;

        for (int i = 0; i < len; i++) {
            int left = i, right = i, count = 0;
            unordered_map<string, int> seen;

            while (right + len <= n) {
                string word = s.substr(right, len);
                right += len;

                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    count++;

                    while (seen[word] > counts[word]) {
                        seen[s.substr(left, len)]--;
                        count--;
                        left += len;
                    }

                    if (count == num)
                        indexes.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return indexes;
    }
};
