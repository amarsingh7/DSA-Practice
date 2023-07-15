int ans;
int dp[1000];
vector<vector<int>> graph;

class Solution {
public:
    void dfs(int cur, int par, int d) {
        dp[cur] = d;
        for (auto sub : graph[cur]) {
            if (sub != par) {
                if (dp[sub] > d + 1) {
                    // Explore another path and it is possible to find a shorter cycle
                    dfs(sub, cur, d + 1);
                } 
                else if (dp[sub] < d) {
                    ans = min(ans, d - dp[sub] + 1);  // Cycle detected
                }
            }
        }
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        ans = INT_MAX;
        graph.clear();
        graph.resize(n);
        for (int i = 0; i < n; ++i)
            dp[i] = INT_MAX;
        
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
            if (dp[i] == INT_MAX) 
                dfs(i, -1, 0); // DFS on each connected sub-graph
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
