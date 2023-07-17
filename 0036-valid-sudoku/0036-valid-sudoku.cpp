class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 9; ++i) {
        vector<bool> rowCheck(9, false);
        for (int j = 0; j < 9; ++j) {
            char current = board[i][j];
            if (current != '.') {
                int num = current - '1';
                if (rowCheck[num]) {
                    return false;
                }
                rowCheck[num] = true;
            }
        }
    }

    // Check columns
    for (int j = 0; j < 9; ++j) {
        vector<bool> colCheck(9, false);
        for (int i = 0; i < 9; ++i) {
            char current = board[i][j];
            if (current != '.') {
                int num = current - '1';
                if (colCheck[num]) {
                    return false;
                }
                colCheck[num] = true;
            }
        }
    }

    // Check subgrids
    for (int k = 0; k < 9; ++k) {
        vector<bool> subgridCheck(9, false);
        int startRow = (k / 3) * 3;
        int startCol = (k % 3) * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                char current = board[i][j];
                if (current != '.') {
                    int num = current - '1';
                    if (subgridCheck[num]) {
                        return false;
                    }
                    subgridCheck[num] = true;
                }
            }
        }
    }

    return true;
}

};