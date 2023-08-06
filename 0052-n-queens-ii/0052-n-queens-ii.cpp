class Solution {
public:
    
    int ans=0; 
    bool isvalid(vector<string> &board, int row, int col)
    {
        for(int i=row; i>=0; i--)
            if(board[i][col]=='Q')  // complete col
                return false;
        for(int i=row, j=col; i>=0 and j>=0; i--,j--)  
            if(board[i][j]=='Q')    // left diagonal
                return false;
        for(int i=row, j=col; i>=0 and j<board.size(); i--, j++)
            if(board[i][j]=='Q')    // right diagonal
                return false;
        return true;
    }
    void dfs(vector<string> &board, int row)
    {
        if(row== board.size())     // exploration done
        {
            ans++;
            return;
        }
            
        for(int i=0; i<board.size(); i++)
        {
            if(isvalid(board, row, i))
            {
                board[row][i]= 'Q';     // safe positon
                dfs(board, row+1);      // move to next row
                board[row][i]= '.';     // backtrack
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        
        return ans;
    }
};