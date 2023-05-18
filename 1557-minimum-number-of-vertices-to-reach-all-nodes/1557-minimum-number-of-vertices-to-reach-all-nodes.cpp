class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> v;
        vector<bool> iiee(n, false);
        for(int i=0; i<edges.size(); i++)
        {
            for(int j=0; j<edges[0].size(); j++)
            {
                iiee[edges[i][1]]= true;
            }
        }
        vector<int> rnodes;
        for(int i=0; i<n; i++)
        {
            if(!iiee[i])
                rnodes.push_back(i);
        }
        return rnodes;
    }
};