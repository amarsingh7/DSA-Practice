//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int ans=0;
        string bn;
        while(N>0)
        {
            bn= to_string(N%2) +bn;
            N= N/2;
        }
        for(int i=0; i<bn.size(); i++)
        {
            if(bn[i]=='1')
                ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends