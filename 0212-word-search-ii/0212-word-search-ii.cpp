#define ALPHABET_SIZE 26

class Solution {
public:
    int idx[4] = {-1, 0, 1, 0};
    int idy[4] = {0, 1, 0, -1};
    vector<string> res;
    struct trieNode {
        struct trieNode* child[ALPHABET_SIZE];
        string word;
        bool end;

        trieNode() {
            end = false;
            for(int i=0; i<ALPHABET_SIZE; i++) {
                child[i] = NULL;
            }
            word = "";
        }
    };
    
    void buildTrie(struct trieNode* root, string word) {
        struct trieNode* p = root;

        int index;
        for(char c : word) {
            int index = c - 'a';
            if(p->child[index] == NULL) {
                p->child[index] = new trieNode();
            }
            p = p->child[index];
        }
        //inserting word at the end, so that we can directly push into our result list while searching
        p->word = word;  
        p->end = true;
    }
    
    bool isValid(int i, int j, int row, int col) {
        if(i<0 || i>=row || j<0 || j>=col)
            return false;

        return true;
    }

    void dfs(vector<vector<char>>& board, int i, int j, struct trieNode* root) {
        if(!isValid(i, j, board.size(), board[0].size()) || board[i][j] == '#') {
            return;
        }
        struct trieNode* p = root;
        char c = board[i][j];
        int index = c - 'a';

        if(p->child[index] == NULL) {
            return;
        }
        else {  //letter exist
            
            if(p->child[index]->end == true) {    //end of a word that present in board also
                res.push_back(p->child[index]->word);
                p->child[index]->end = false;   //making false so that we can't find this word again with some other path.
            }

            board[i][j] = '#';

            //continue to search
            for(int k=0; k<4; k++) {
                dfs(board, i+idx[k], j+idy[k], p->child[index]);
            }
            board[i][j] = c;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();

        struct trieNode* root = new trieNode();

        //build trie for input words
        for(int i=0; i<words.size(); i++) {
            buildTrie(root, words[i]);
        }

        //making every cell as a starting index, and checking is there is word from that starting cell.
        //it will reduce the cost to look every starting point(every cell) for every word.
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                dfs(board, i, j, root);               
            }
        }
        return res;      
    }
};