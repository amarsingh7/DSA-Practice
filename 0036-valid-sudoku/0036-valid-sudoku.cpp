class Solution {
public:
   bool isValidSudoku(vector<vector<char>>& grid) {
    for (int i = 0; i < 9; i++) {
        unordered_set<char> rowSet, colSet, gridSet;
        
        for (int j = 0; j < 9; j++) {
            // Check row
            int rowId = grid[i][j];
            if (rowId != '.') {
                if (rowSet.count(rowId)) {
                    return false;
                }
                rowSet.insert(rowId);
            }
            
            // Check column
            int colId = grid[j][i];
            if (colId != '.') {
                if (colSet.count(colId)) {
                    return false;
                }
                colSet.insert(colId);
            }
            
            // Check grid
            int gridRow = 3 * (i / 3) + j / 3;
            int gridCol = 3 * (i % 3) + j % 3;
            int gridId = grid[gridRow][gridCol];
            if (gridId != '.') {
                if (gridSet.count(gridId)) {
                    return false;
                }
                gridSet.insert(gridId);
            }
        }
    }
    
    return 1;
}


};