class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r= mat.size();
        int c= mat[0].size();
        
        vector<pair<int, int>> res;
        int count=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            res.push_back({count, i}); 
            count=0;
        } 
        sort(res.begin(), res.end(), [](pair<int, int>&a, pair<int, int> &b){
            if(a.first==b.first)   
                return a.second< b.second;
            return a.first< b.first;
        });
        vector<int> ans;
        
        for(int i=0; i<k; i++)
        {
            ans.push_back(res[i].second);
        }
        
        return ans;
        
    }
};