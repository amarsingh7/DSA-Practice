class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<vector<int>> ans;
    
    void dfs(int node)
    {
        while(graph[node].size())
        {
            int x= graph[node].back();
            graph[node].pop_back();
            dfs(x);
            ans.push_back({node, x});
        } 
            
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> indegree;
        for(auto &x:pairs)
        {
            graph[x[0]].push_back(x[1]);
            ++indegree[x[0]];
            --indegree[x[1]];
        }
        int start= -1;
        for(auto &x:indegree)
        {
            if(x.second>0)
                start= x.first;
        }
        if(start== -1)
            start= pairs[0][0];
            
        dfs(start);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};