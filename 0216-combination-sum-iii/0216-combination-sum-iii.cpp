class Solution {
public:
    
    void search(vector<int>& num, int next, vector<int>& pSol, int n, vector<vector<int> >& result, int k)
    {
        if(n == 0 and k==0)
        {
            result.push_back(pSol);
            return;
        }
        
        if(n<0 || k<0 || next==num.size())
            return;
            
        search(num, next+1, pSol, n, result, k);
        pSol.push_back(num[next]);
        
        search(num, next + 1, pSol, n- num[next], result, k-1);
        pSol.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> num= {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> psol;
        search(num, 0, psol, n, result, k);
        return result;
    }
};