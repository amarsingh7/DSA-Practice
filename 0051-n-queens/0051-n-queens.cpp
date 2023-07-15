class Solution {
public:
    vector<vector<string >> ans;
        
    bool isvalid(vector<string> &board, int row, int col)
    {
        for(int i=row; i>=0; i--)
            if(board[i][col]=='Q')  // complete col
                return false;
        for(int i=row, j=col; i>=0 and j>=0; i--,j--)  // left diagonal
            if(board[i][j]=='Q')
                return false;
        for(int i=row, j=col; i>=0 and j<board.size(); i--, j++)
            if(board[i][j]=='Q')
                return false;
        return true;
    }
    void dfs(vector<string> &board, int row)
    {
        if(row== board.size())
        {
            ans.push_back(board);
            return;
        }
            
        for(int i=0; i<board.size(); i++)
        {
            if(isvalid(board, row, i))
            {
                board[row][i]= 'Q';
                dfs(board, row+1);
                board[row][i]= '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        
        return ans;                             
                            
    }
};