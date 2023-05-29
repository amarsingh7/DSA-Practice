//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int maxSumWithK(long long int a[], long long int n, long long int k) 
{
    long long int ans=0;
    for(int i=0; i<k; i++)
    {
        ans+= a[i];
    }
    long long int fans= ans, lsum=0, lmin=0;
    for(int i=k; i<n; i++)
    {
        ans+= a[i];
        lsum+= a[i-k];
        lmin= min(lmin, lsum);
        fans= max(fans, ans-lmin);
    }
    return fans;
}