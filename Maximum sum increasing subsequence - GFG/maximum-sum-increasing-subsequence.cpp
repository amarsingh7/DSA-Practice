//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1001];
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    for(int i=0; i<n; i++)
	        dp[i]= arr[i];
	    int maxi= arr[0];
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<i; j++)
	        {
	            if(arr[j]<arr[i] and (arr[i] +dp[j])>dp[i])
	                dp[i]= arr[i]+ dp[j];
	        }
	        maxi= max(maxi, dp[i]);
	    }
	    
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends