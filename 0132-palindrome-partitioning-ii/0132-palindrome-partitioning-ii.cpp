class Solution {
public:
    int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, INT_MAX); 
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false)); 
        // to store palindrome information

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            if (s[i] == s[j] && (i - j <= 1 || isPalindrome[j + 1][i - 1]))             {
                isPalindrome[j][i] = true; 
                // mark substring s[j..i] as palindrome
                if (j == 0) 
                    dp[i] = 0; // no cuts needed for the substring s[0..i]
                else
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                // update the minimum cuts
            }
        }
    }

    return dp[n - 1]; // minimum cuts for the entire string s
}

};