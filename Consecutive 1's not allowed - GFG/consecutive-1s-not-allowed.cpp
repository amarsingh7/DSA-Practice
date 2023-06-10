//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    int mod = 1e9 + 7;
        vector<ll> dp(n + 1, 0);
    
        dp[1] = 2;  // For n = 1, there are 2 valid binary strings: "0" and "1"
        dp[2] = 3;  // For n = 2, there are 3 valid binary strings: "00", "01", "10"
    
        for (int i = 3; i <= n; i++) 
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        
    
        return dp[n];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends