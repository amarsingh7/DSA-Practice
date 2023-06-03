//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string expandAroundCenter(string s, int left, int right) {
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right]) {
        --left;
        ++right;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalin(string s) {
    int n = s.length();
    if (n < 2) {
        return s;
    }

    string longestPal = "";
    for (int i = 0; i < n; ++i) {
        string oddPal = expandAroundCenter(s, i, i);
        if (oddPal.length() > longestPal.length()) {
            longestPal = oddPal;
        }

        string evenPal = expandAroundCenter(s, i, i + 1);
        if (evenPal.length() > longestPal.length()) {
            longestPal = evenPal;
        }
    }

    return longestPal;
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends