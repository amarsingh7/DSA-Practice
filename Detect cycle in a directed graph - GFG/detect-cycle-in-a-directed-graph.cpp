//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
bool dfs(int v, vector<int>& visited, vector<int> adj[]) 
{
    visited[v] = 1; // Mark the current vertex as visited

    for (int child : adj[v]) {
        if (visited[child] == 1)
            return true; // Found a back edge, cycle detected
        else if (visited[child] == 0 && dfs(child, visited, adj))
            return true; // Recursive call to child found a cycle
    }

    visited[v] = 2; // Mark the current vertex as visited and processed
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0); 

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dfs(i, visited, adj)) {
            return true; // Found a cycle
        }
    }

    return false; // No cycle found
}
    
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends