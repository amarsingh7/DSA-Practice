//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int findParent(int v, vector<int>& parent) {
        if (parent[v] == v)
            return v;
        return findParent(parent[v], parent);
    }

    vector<int> fck(int V, vector<vector<int>> adj[]) {
        vector<int> res;
        vector<int> parent(V);
        for (int i = 0; i < V; i++)
            parent[i] = i;
        int count = 0;
        vector<vector<int>> edges;

        // Construct the list of edges (u, v, w) from the adjacency list
        for (int i = 0; i < V; i++) {
            for (auto x : adj[i]) {
                int v = x[0];
                int w = x[1];
                edges.push_back({i, v, w});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });

        for (auto x : edges) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            int parentU = findParent(u, parent);
            int parentV = findParent(v, parent);
            if (parentU != parentV) {
                res.push_back(w);
                parent[parentU] = parentV; // Union the sets
                count++;
            }
            if (count == V - 1)
                break;
        }
        return res;
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> vec = fck(V, adj);

        return accumulate(vec.begin(), vec.end(), 0LL);
    }

};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends