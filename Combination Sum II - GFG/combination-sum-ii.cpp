//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void search(vector<int>& num, int next, vector<int>& pSol, int target, vector<vector<int> >& result)
    {
        if(target == 0)
        {
            result.push_back(pSol);
            return;
        }
        
        if(next == num.size() || target - num[next] < 0)
            return;
            
        for (int i = next; i < num.size(); i++)
        {
        // Skip duplicate elements
            if (i > next && num[i] == num[i - 1])
            continue;

            pSol.push_back(num[i]);
            search(num, i + 1, pSol, target - num[i], result); // Update next to i + 1
            pSol.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        // Write your code here
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        vector<int> pSol;
        search(nums, 0, pSol, target, result);
        return result;  
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends