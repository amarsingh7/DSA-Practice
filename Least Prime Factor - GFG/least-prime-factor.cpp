//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  bool isprime(int i)
    {
        if(i<=1)
            return false;
        for(int j=2; j*j<=i; j++){
            if(i%j==0)
                return false;
        }
        return true;
    }
    
    int ans(int n)
    {
        int res=0;
        for(int i=1; i<=n; i++){
            if(n%i==0 and isprime(i)){
                res=i;
                break;
            }
        }
        return res;
    }
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> vec(n+1);
        vec[1]=1;
        for(int i=2; i<=n; i++)
            vec[i]= ans(i);
        return vec;
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
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends