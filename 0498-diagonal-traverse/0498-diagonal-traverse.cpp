class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r= mat.size();
        int c= mat[0].size();
        
        vector<int> ans;
        vector<vector<int>> diagonal(r+c-1);
        
        // making the diagonal matrix, cells having same i+j value 
        // are in same diagonal line
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                diagonal[i+j].push_back(mat[i][j]);
            }
        }
        // if i is odd, order of diag is same, if even, order is reversed
        for(int i=0; i<r+c-1; i++)
        {
            if(i%2==0)
                reverse(diagonal[i].begin(), diagonal[i].end());
        }
        // iterate over the diagonal matrix and store it in ans vector
        for(auto x:diagonal)
            for(auto y:x)
                ans.push_back(y);
        
        return ans;
    }
};