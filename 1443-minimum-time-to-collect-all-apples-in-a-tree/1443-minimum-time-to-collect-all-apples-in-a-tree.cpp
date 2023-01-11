class Solution {
int postOrder(int node, vector<vector<int>>& adj, vector<bool>& hasApple, int par){
        int ans = 0;
        for(auto neigh: adj[node])
        {
            if(neigh == par)
                continue;
            ans += postOrder(neigh, adj, hasApple, node);
        }
        if(hasApple[node] == true || ans > 0)
            ans += 2;
        return ans;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = postOrder(0, adj, hasApple, -1);
        
        return (ans > 0) ? ans - 2: 0;   
    }
};