class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sumf=0, sumc=0;
        int n= mat.size();
        for(int i=0; i<n; i++)
        {
            sumf+= mat[i][i];
            sumc+= mat[n-1-i][i]; 
            
        }
        int ans= sumf+sumc;
        if(n%2 !=0)
                return ans- mat[ceil(n/2)][ceil(n/2)];
        return ans;
    }
};