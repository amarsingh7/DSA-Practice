//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    bool dfs(int i, int n, int k, int t, vector<int> &coins, vector<vector<vector<int>>> &dp) {
        if(i == n) 
            return false;
        if(!k) 
            return !t;
        if(dp[i][k][t] != -1) 
            return dp[i][k][t];

        bool notpick = dfs(i + 1, n, k, t, coins, dp);
        bool pick = t - coins[i] >= 0 ? dfs(i + 1, n, k - 1, t - coins[i], coins, dp) or   dfs(i, n, k - 1, t - coins[i], coins, dp) : false;

        return dp[i][k][t] = pick  or notpick;
    }
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(K + 1, vector<int>(target + 1 , -1)));
        return dfs(0, N, K, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends