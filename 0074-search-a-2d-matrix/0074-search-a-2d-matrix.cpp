class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        bool ans= false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<matrix[i].size(); j++)
            {
                if(matrix[i][j] == target)
                {
                    ans = true;
                    //break;
                }
                
            }
        }
        return ans;
    }
};