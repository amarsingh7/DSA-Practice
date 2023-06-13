class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        int count = 0;
        vector<vector<int>> grid2(c, vector<int>(r));

        for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++)
            grid2[j][i] = grid[i][j];
        }

        for (auto& row : grid) {
        for (auto& column : grid2) {
            if (row == column)
                count++;
            }
        }
        return count;

    }
};