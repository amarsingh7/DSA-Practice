class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row= matrix.size();
        int col= matrix[0].size();
        int res= INT_MIN;
        for(int i=0; i<col; i++)
        {
            vector<int> sum(row, 0);
            for(int j=i; j<col; j++)
            {
                for(int k=0; k<row; k++)
                {
                    sum[k] += matrix[k][j];
                }
                set<int> s;
                s.insert(0);
                int csum=0, omax=INT_MIN;
                
                for(auto x:sum)
                {
                    csum+= x;
                    auto it= std::lower_bound(s.begin(), s.end(), csum-k);
                    if(it !=s.end())
                        omax= max(omax, csum- *it);
                    s.insert(csum);
                }
                res= max(res, omax);
            }
        }
        return res;
    }
};