class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r= mat.size();
        int c= mat[0].size();
        
        vector<int> ans;
        vector<vector<int>> diagonal(r+c-1);
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                diagonal[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0; i<r+c-1; i++)
        {
            if(i%2==0)
                reverse(diagonal[i].begin(), diagonal[i].end());
        }
        for(auto x:diagonal)
            for(auto y:x)
                ans.push_back(y);
        
        return ans;
    }
};