class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n= matrix.size();
//         bool ans= false;
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<matrix[i].size(); j++)
//             {
//                 if(matrix[i][j] == target)
//                 {
//                     ans = true;
//                     //break;
//                 }
                
//             }
//         }
//         return ans;
        int i=0, j= matrix[0].size() -1;
        bool ans= false;
        while(i< matrix.size() and j>=0)
        {
            if(matrix[i][j]== target){
                ans= true; return ans;
            }
                
            else if(matrix[i][j]> target)
                j--;
            else
                i++;
        }
        return ans;
    }
};