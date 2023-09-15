class Solution {
public:
    int par[1001]; // Array to represent disjoint sets
    
    // Find function to find the representative of a set
    int find(int a)
    {
        if(par[a] < 0) // If the parent is negative, it's a root node
            return a;
        return par[a] = find(par[a]); 
        // Path compression for efficiency
    }
    
    // Union function to merge two sets
    void unify(int a, int b)
    {
        par[a] = b; 
        // Make one set's representative point to the other
    }
    
    // Minimum Spanning Tree algorithm using Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); // Number of points
        int ans = 0; // Initialize the answer
        
        memset(par, -1, sizeof(par)); 
        // Initialize the disjoint set data structure
        
        vector<pair<int, pair<int, int>>> vpii; 
        // Vector to store edges with weights
        
        // Generate all possible edges and calculate weights
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                // Calculate the weight as the sum of absolute differences
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                
                // Store the weight and the pair of points (edges)
                vpii.push_back({weight, {i, j}});
            }
        }
        
        // Sort the edges in ascending order of weight
        sort(vpii.begin(), vpii.end());
        
        // Iterate through the sorted edges and build the MST
        for(auto x : vpii)
        {
            int a = x.second.first;
            int b = x.second.second;
            
            // Check if adding this edge doesn't create a cycle in mst
            if(find(a) != find(b)){
                ans += x.first; 
                // Add the weight of the edge to the total cost
                unify(find(a), find(b)); // Merge the sets
            } 
        }
        return ans; // Return the minimum cost to connect all points
    }
};
