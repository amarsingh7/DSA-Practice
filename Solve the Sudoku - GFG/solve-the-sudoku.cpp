//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                if (grid[row][col] == 0) 
                {
                    for (int x = 1; x <= 9; x++) 
                    {
                        if (isvalid(grid, row, col, x)) {
                            grid[row][col] = x;
                            if (SolveSudoku(grid))
                                return true;
                            else
                                grid[row][col] = 0; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    bool isvalid(int board[N][N], int row, int col, int val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val)   // row check
                return false;
            if (board[i][col] == val)   // col check
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;           // 3*3 grid check
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout << grid[i][j]<<" ";
        }
    }
    
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends