class Solution {
public:
    
    int countPalindromicSubsequences(string s) {
    int n = s.size();
    long mod = 1e9 + 7;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Base case: Single characters are palindromes.
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;
    
    // Fill in the dp table using bottom-up dynamic programming.
    // Upper triangular matrix
    for (int gap = 1; gap < n; ++gap) {
        for (int i = 0, j = i + gap; j < n; ++i, ++j) {
            // If characters at ends are not the same.
            if (s[i] != s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            } 
            else {
                // If characters at ends are the same.
                dp[i][j] = 2 * dp[i+1][j-1];
                
                int l = i+1, r = j-1;
                while (l <= r && s[l] != s[i]) l++; // Move left pointer.
                while (l <= r && s[r] != s[i]) r--; // Move right pointer.
                
                if (l < r) {
                    // Subtract the overcounted cases.
                    dp[i][j] -= dp[l+1][r-1];   
                }
                
                if (l == r) {
                    // Add the single character palindromes.
                    dp[i][j] += 1;
                }
                
                if (l > r) {
                    // Add the palindrome composed of repeated characters.
                    dp[i][j] += 2;
                }
            }
            
            // Ensure result stays within modulo range.
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
    
    return dp[0][n-1]; // Return the final result.
}

};
