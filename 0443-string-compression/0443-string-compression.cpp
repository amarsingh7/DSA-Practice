class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
    if (n < 2) return n;

    int left = 0, right = 0;

    while (right < n) {
        chars[left] = chars[right];
        int count = 0;
        while (right < n && chars[right] == chars[left]) {
            count++;
            right++;
        }

        if (count == 1) {
            left++;
        } else {
            string cnt = to_string(count);
            for (auto digit : cnt) {
                chars[++left] = digit;
            }
            left++;
        }
    }

    return left;
    }
};