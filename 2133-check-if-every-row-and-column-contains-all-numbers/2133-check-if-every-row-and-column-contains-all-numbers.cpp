class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n= matrix.size();
        for(int i=0; i<n; i++)
        {
            vector<bool> rcheck(n, false);
            for(int j=0; j<n; j++)
            {
                int fck= matrix[i][j];
                if(rcheck[fck-1])
                    return false;
                rcheck[fck-1]= true;
            }
        }
        
        for(int j=0; j<n; j++)
        {
            vector<bool> ccheck(n, false);
            for(int i=0; i<n; i++)
            {
                int fck= matrix[i][j];
                if(ccheck[fck-1])
                    return false;
                ccheck[fck-1]= true;
            }
        }
        return true;
    }
};