class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string str= to_string(x);
        int cnt=0;
        int l = 0;
        int h = str.size() - 1;
 
        while (h > l) {
        if (str[l++] != str[h--]) {
            cnt++;
        }
        }
        if(cnt>0) return false;
        return true;
    }
};