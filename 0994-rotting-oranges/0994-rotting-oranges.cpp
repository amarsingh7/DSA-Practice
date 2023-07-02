class Solution {
public:
  
void dfs(vector<vector<int>>& grid, int i, int j, int minutes) {
    int n = grid.size();
    int m = grid[0].size();

    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    if(grid[i][j] == 0 || (1 < grid[i][j] && grid[i][j] < minutes))
        return;

    grid[i][j] = minutes;
    dfs(grid, i - 1, j, minutes + 1);
    dfs(grid, i + 1, j, minutes + 1);
    dfs(grid, i, j - 1, minutes + 1);
    dfs(grid, i, j + 1, minutes + 1);
}

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty())
        return -1;

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2)
                dfs(grid, i, j, 2);
        }
    }

    int minutes = 2;
    for (auto& row : grid) {
        for (int cell : row) {
            if (cell == 1)
                return -1;
            minutes = max(minutes, cell);
        }
    }

    return minutes - 2;
}
};