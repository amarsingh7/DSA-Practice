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
    
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            vector<bool> subgridCheck(9, false);
            for (int i = 0; i < 9; ++i) {
                    char current = board[3*(row/3) + i/3][3*(col/3) + i%3];
                    if (current != '.') {
                        if (subgridCheck[current-'1']) 
                            return false;
                        subgridCheck[current-'1'] = true;
                    }
            }
        }
    }    
        
    return true;
}

};