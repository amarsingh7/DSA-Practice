//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<bool> visited;
    void dfs(vector<int> adj[], int V, vector<bool> &visited, vector<int> &ans)
    {
        visited[V]= true;
        ans.push_back(V);
        for(auto child: adj[V])
        {
            if(!visited[child])
            dfs(adj, child, visited, ans);
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        visited.resize(V, false);
        vector<int> ans;
        dfs(adj, 0, visited, ans);
        for(int i=1; i<V; i++)
        {
            if(!visited[i])
                dfs(adj, i, visited, ans);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends