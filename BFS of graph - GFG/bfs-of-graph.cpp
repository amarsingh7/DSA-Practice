//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<bool> visited;
    void bfs(vector<int> adj[], vector<bool> visited, int v, vector<int> &ans)
    {
        queue<int> q;
        visited[v]=true;
        q.push(v);
        while(!q.empty())
        {
            int curr= q.front();
            q.pop();
            ans.push_back(curr);
            for(auto x:adj[curr])
            {
                if(!visited[x])
                {
                    visited[x]= true;
                    q.push(x);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        visited.resize(V, false);
        bfs(adj, visited, 0, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends