class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m= matrix.size();
        if(m==0)    
            return 0;
        int n= matrix[0].size();
        vector<vector<int>> vec(m, vector<int>(n));
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]=='0')
                    continue;
                int w= vec[i][j]= (j? vec[i][j-1]:0)+1;
                for(int k=i; k>=0; k--)
                {
                    w= min(w, vec[k][j]);
                    ans= max(ans, w*(i-k+1));
                }
            }
        }
        return ans;
    }
};