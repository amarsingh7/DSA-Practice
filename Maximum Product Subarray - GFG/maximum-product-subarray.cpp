//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	    long long ans= INT_MIN;
	    long long sum=1;
	    for(int i=0; i<n; i++)
	    {
	        sum *= nums[i];
	        ans= max(ans, sum);
	        if(sum==0)
	            sum=1;
	    }
	    sum=1;
	    for(int i=n-1; i>=0; i--)
	    {
	        sum *= nums[i];
	        ans= max(ans, sum);
	        if(sum==0)
	            sum=1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends