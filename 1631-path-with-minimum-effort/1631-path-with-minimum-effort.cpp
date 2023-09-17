class Solution {
public:
    int dp[101][101];
    bool isvalid(int i, int j, vector<vector<int>>&heights)
    {
        int r= heights.size();
        int c= heights[0].size();
        if(i<0 || j<0 || i>= r || j>= c)
            return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    int dirs[5] = {-1, 0, 1, 0, -1};

    std::vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.emplace(0, 0); // First item is effort, second is row * 100 + col
    while (!pq.empty()) {
      int effort = pq.top().first;
      int x = pq.top().second / 100, y = pq.top().second % 100;
      pq.pop();

      if (effort >= efforts[x][y]) continue;
      efforts[x][y] = effort;

      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i], ny = y + dirs[i + 1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
        pq.emplace(n_effort, nx * 100 + ny);
      }
    }
    return efforts[m-1][n-1];
  }
    
};