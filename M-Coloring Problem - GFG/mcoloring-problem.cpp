//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
bool isValid(vector<vector<int>>& adj, vector<int>& colored, int node, int color) {
    // Check if the node is already colored with the given color
    if (colored[node]) {
        return false;
    }

    // Check if any neighboring node has the same color as the given color
    for (auto u : adj[node]) {
        if (colored[u] == color) 
            return false;
    }

    // If the node can be colored with the given color without any conflict, return true
    return true;
}

bool graphColoringHelper(vector<vector<int>>& adj, vector<int>& colored, int m, int n, int idx) {
    // Base case: If all nodes are colored, return true
    if (idx == n) {
        return true;
    }

    // Try coloring the current node with each of the m colors (1 to m)
    for (int i = 1; i <= m; i++) {
        // Check if coloring the node with color i is valid
        if (isValid(adj, colored, idx, i)) {
            // Color the node with color i
            colored[idx] = i;

            // Recursively try coloring the next node
            if (graphColoringHelper(adj, colored, m, n, idx + 1)) {
                return true;
            }

            // Backtrack: If coloring the node with color i does not lead to a valid coloring,
            // uncolor the node and try the next color
            colored[idx] = 0;
        }
    }

    // If no color leads to a valid coloring for the current node, return false
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int N = 101;
    vector<vector<int>> adj(n);
    vector<int> colored(n, 0);

    // Convert the given adjacency matrix into an adjacency list
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                adj[i].push_back(j);
            }
        }
    }

    // Call the recursive helper function to color the graph
    return graphColoringHelper(adj, colored, m, n, 0);
}

};
    // 


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends