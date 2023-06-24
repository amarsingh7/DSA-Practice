//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &t) {
        // code here
        int mx=0,mx_cnt=0;
        unordered_map<char,int>m;
        for(auto c : t){
            m[c]++;
            mx=max(mx,m[c]);
        }
        for(auto it: m){
            if(it.second==mx)mx_cnt++;
        }
        int val=mx_cnt+(mx-1)*(k+1);
        return max(val,n);
        /*
        1. mx_cnt represents the number of tasks with the maximum frequency. 
           These tasks will be placed in the intervals without any cooling time.
        2. (mx - 1) * (k + 1) represents the number of intervals needed for the 
          remaining tasks. Each interval contains k units of cooling time, and 
          there are mx - 1 remaining tasks after placing the tasks with max frequency.
        */
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends