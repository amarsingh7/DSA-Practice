//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int l=1;
        int r= 1e9;
        while(l<r)
        {
            int mid= l+(r-l)/2;
            int ans=0;
            for(auto x:piles)
            {
                ans += (x+mid-1)/mid;
            }
            if(ans>H)
                l= mid+1;
            else
                r= mid;
        }
        return l;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends