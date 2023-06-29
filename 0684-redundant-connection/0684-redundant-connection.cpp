class Solution {
public:

vector<int> visited;
vector<vector<int>> graph;
vector<int> cycleNodes;

bool dfs(int node, int target) {
    if (visited[node])
        return false;

    visited[node] = 1;

    if (node == target)
        return true;

    for (int child : graph[node]) {
        if (dfs(child, target))
            return true;
    }

    return false;
}

bool hasPath(int u, int v) {
    visited.assign(graph.size() + 1, 0);
    return dfs(u, v);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    graph.resize(n + 1);

    vector<int> ans;

    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        if (hasPath(u, v)) {
            cycleNodes = { u, v };
            break;
        }

        graph[u].push_back(v);
        graph[v].push_back(u);
        ans = edge;
    }

    return cycleNodes;
    }
};