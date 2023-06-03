class Solution {
public:
    string expandAroundCenter(string s, int left, int right) {
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right]) 
    {
        --left;
        ++right;
    }
    return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
    int n = s.length();
    if (n < 2) 
        return s;

    string ans = "";
    for (int i = 0; i < n; i++) 
    {
        string oddPal = expandAroundCenter(s, i, i);
        if (oddPal.length() > ans.length()) 
            ans = oddPal;

        string evenPal = expandAroundCenter(s, i, i + 1);
        if (evenPal.length() > ans.length()) 
            ans = evenPal;
    }

    return ans;
    }
};