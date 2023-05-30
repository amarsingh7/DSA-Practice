//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int m, n;
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) 
            return false;
        if (k == word.length() - 1) 
            return true;  // found the last char

        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfsSearch(board, word, k+1, i-1 ,j) 
                        || dfsSearch(board, word, k+1, i+1, j) 
                        || dfsSearch(board, word, k+1, i, j-1)
                        || dfsSearch(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        if (word.empty()) 
            return true;
        if (board.empty() || board[0].empty()) 
            return false;
        
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                // traverse the board to find the first char
                if (dfsSearch(board, word, 0, i, j)) 
                    return true;
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends