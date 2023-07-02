//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    vector<int> visited;
    bool dfs(int v, int p, vector<int> adj[], vector<int> &visited)
    {
        visited[v]= true;
        for(auto child:adj[v])
        {
            if(!visited[child])
            {
                if(dfs(child, v, adj, visited))
                    return true;
            }
            else
            {
                if(child != p)
                    return true;
            }
                
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        visited.resize(V+1, 0);
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends