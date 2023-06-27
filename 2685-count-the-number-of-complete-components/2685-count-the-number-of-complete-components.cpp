class Solution {
public:
    void dfs(int v, int &vertices, int &edges, vector<vector<int>> &temp,
    vector<int> &visited) {
        visited[v] = 1;
        vertices++;
        edges += temp[v].size();
        for (auto to : temp[v]) {
            if (!visited[to])
                dfs(to, vertices, edges, temp, visited);
        }
    }
    int countCompleteComponents(int V, vector<vector<int>>& adj) {
        int ans = 0;
        vector<int> visited(V + 1, 0);
        
        vector<vector<int>> temp(V+1);
        for (const auto& e : adj) {
            temp[e[0]].push_back(e[1]);
            temp[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                int vertices = 0, edges = 0;
                dfs(i, vertices, edges, temp, visited);
                edges /= 2;
                if (edges == (vertices * (vertices - 1)) / 2) ans++;
            }
        }
        return ans;
    }
};