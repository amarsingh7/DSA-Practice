class Solution {
public:
    string shortestPalindrome(string s) {
    // KMP Algo
    string rev(s);
    reverse(rev.begin(), rev.end());

    string combined = s + "#" + rev;
    int n = combined.size();

    vector<int> lps(n, 0);  // Longest Proper Prefix which is also Suffix

    for (int i = 1, j = 0; i < n; ) 
    {
        if (combined[i] == combined[j]) 
            lps[i++] = ++j;
        else 
        {
            if (j != 0) 
                j = lps[j - 1];
            else 
                lps[i++] = 0;
        }
    }
    return rev.substr(0, s.size() - lps[n - 1]) + s;
    }

};