class Solution {
public:
    int dx[4]= {-1, 1, 0, 0};
    int dy[4]= {0, 0, -1, 1};
    
    bool boundary(int i, int j, int &m, int &n){
        return (i==m-1 || j==n-1 || i==0 || j==0);
    } 
        
    bool valid(int i, int j, int m, int n){
        return (i>=0 and j>=0 and i<m and j<n);
    } 
        
    void notclosed(int i, int j, int m, int n, vector<vector<char>>&board)
    {
        board[i][j]= 'N';
        for(int k=0; k<4; k++)
        {
            int ii= i+dx[k];
            int jj= j+dy[k];
            if(valid(ii, jj, m, n) and board[ii][jj]=='O')
                notclosed(ii, jj, m, n, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(boundary(i, j, m, n) and board[i][j]=='O')
                    notclosed(i, j, m, n, board);
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='N')
                    board[i][j]='O';
            }
        }
    }
};