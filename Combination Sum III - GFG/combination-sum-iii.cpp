//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void search(vector<int>& num, int next, vector<int>& pSol, int n, vector<vector<int> >& result, int k)
    {
        if(n == 0 and k==0)
        {
            result.push_back(pSol);
            return;
        }
        
        if(n<0 || k<0 || next==num.size())
            return;
            
        search(num, next+1, pSol, n, result, k);
        pSol.push_back(num[next]);
        
        search(num, next + 1, pSol, n- num[next], result, k-1);
        pSol.pop_back();
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>> result;
        vector<int> num= {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> psol;
        search(num, 0, psol, N, result, K);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends