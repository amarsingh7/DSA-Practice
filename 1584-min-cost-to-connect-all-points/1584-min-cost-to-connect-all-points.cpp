class Solution {
public:
    // USING DSU IN THE MINIMUM SPANNING TREE PROBLEM
    
    int par[1001];
    int find(int a)
    {
        if(par[a]<0)
            return a;
        return par[a]= find(par[a]);
    }
    void unify(int a, int b)
    {
        par[a]= b;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        int ans=0;
        
        memset(par, -1, sizeof(par));
        
        vector<pair<int, pair<int, int>>> vpii;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int weights= abs(points[i][0]- points[j][0]) + abs(points[i][1]- points[j][1]);
                
                vpii.push_back({weights, {i, j}});
            }
        }
        
        sort(vpii.begin(), vpii.end());
        
        for(auto x:vpii)
        {
            int a= x.second.first;
            int b= x.second.second;
            
            if(find(a) != find(b)){
                ans+= x.first;
                unify(find(a), find(b));
            } 
            
        }
        return ans;
        
    }
};