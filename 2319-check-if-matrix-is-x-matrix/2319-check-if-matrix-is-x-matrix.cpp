class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        int sumf=0, sumc=0;
        bool ans=true;
        for(int i=0; i<n; i++)
        {
              for(int j=0; j<n; j++)
              {
                  if ((i == j || i + j == n - 1) == !grid[i][j]) 
                      return false;
              }
        
      }
        return true;
    }
};