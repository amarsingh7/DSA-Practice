//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        map<int, int>mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second >n/3)
                ans.push_back(x.first);
        }
        if(ans.size()>=1)
        return ans;
        return {-1};
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
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends