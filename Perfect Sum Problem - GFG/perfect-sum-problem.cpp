//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int perfectSum(int arr[], int n, int sum) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Initialize base cases
        dp[0][0] = 1; // There's one way to make a sum of 0 without using any elements

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int target = 0; target <= sum; target++) {
                dp[i][target] = dp[i - 1][target]; // Do not pick arr[i-1]

                if (arr[i - 1] <= target) {
                    dp[i][target] = (dp[i][target] + dp[i - 1][target - arr[i - 1]]) % mod; // Pick arr[i-1]
                }
            }
        }

        return dp[n][sum];
    }
};
 


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends