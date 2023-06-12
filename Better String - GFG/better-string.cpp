//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int cntsub(string str) 
    {
    int n = str.length();
    int dp[n + 1]; // dp[i] represents the number of distinct subsequences of str[0...i]

    dp[0] = 1; // Empty string has one subsequence

    // Map to store the last occurrence index of each character
    unordered_map<char, int> lastoc;

    for (int i = 1; i <= n; i++) 
    {
        dp[i] = 2 * dp[i - 1]; // Double the count by considering the subsequence without the current character

        if (lastoc.find(str[i - 1]) != lastoc.end()) {
            int prevIndex = lastoc[str[i - 1]];
            dp[i] -= dp[prevIndex - 1]; // Subtract the count of subsequences that include duplicate characters
        }

        lastoc[str[i - 1]] = i; // Update the last occurrence index of the current character
    }

    return dp[n];
}
    string betterString(string str1, string str2) {
        int n= cntsub(str1);
        int m= cntsub(str2);
        if(m>n)
            return str2;
        return str1;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends