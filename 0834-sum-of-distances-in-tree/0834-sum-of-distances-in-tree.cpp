class Solution {
public:
    vector<vector<int>> graph;
    vector<int> res, count;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        res.resize(n, 0);
        count.resize(n, 1);
        
        for(auto x:edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        postorder(0, -1);
        preorder(0, -1);
        
        return res;
    }
    
    void postorder(int root, int par){
        for(auto i: graph[root])
        {
            if(i==par)
                continue;
            postorder(i, root);
            count[root]+= count[i];
            res[root]+= res[i]+ count[i];
        }
    }
    
    void preorder(int root, int par){
        for(auto i:graph[root])
        {
            if(i==par)
                continue;
            res[i]= res[root]+ count.size() -2*count[i];
            preorder(i, root);
        }
    }
};