class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); // Total number of nodes
        int all = (1 << n) - 1; // Mask representing all nodes visited
        
        queue<pair<int, pair<int, int>>> q; 
        // Queue to store node, mask, and cost
        set<pair<int, int>> vis; 
        // Set to keep track of visited nodes and masks
        
        // Initialize the queue and set with starting nodes
        for (int i = 0; i < n; i++) {
            int maskValue = (1 << i); // Create a mask for the current node
            pair<int, pair<int, int>> thisNode(i, make_pair(maskValue, 1)); 
            // Create a pair for the current node, mask, and cost
            q.push(thisNode); // Push the current node onto the queue
            vis.insert({i, maskValue}); // Mark the current node as visited
        }
        
        while (!q.empty()) {
            pair<int, pair<int, int>> curr = q.front(); 
            // Get the front node from the queue
            q.pop(); // Remove the front node from the queue
            
            if (curr.second.first == all) {
                return curr.second.second - 1; 
                // If all nodes are visited, return the cost - 1
            }
            
            for (auto &adj: graph[curr.first]) {
                int bothVisitedMask = curr.second.first;
                bothVisitedMask = bothVisitedMask | (1 << adj); 
                // Update the mask by marking the adjacent node as visited
                
                pair<int, pair<int, int>> ThisNode(adj, make_pair(bothVisitedMask, curr.second.second + 1)); 
                // Create a new pair for the adjacent node
                
                if (vis.find({adj, bothVisitedMask}) == vis.end()) {
                    vis.insert({adj, bothVisitedMask}); 
                    // Mark the adjacent node as visited
                    q.push(ThisNode); // Push the adjacent node onto the queue
                }
            }
        }
        
        return -1;  
    }
};
