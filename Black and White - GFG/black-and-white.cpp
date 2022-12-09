//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int N, int M)
{
    long long mod= 1e9+7 ;
    long long ans=0, a=1, b=2, c=4;
        ans += (long long)(((N*M) - a) * (N*M));
    if(N>=2 && M>=3)    
        ans -= (long long)((N-a) *(c)*(M-b));
    if(N>=3 && M>=2)
        ans -= (long long)((N-b) *(c)*(M-a));
    return ans%mod;
}