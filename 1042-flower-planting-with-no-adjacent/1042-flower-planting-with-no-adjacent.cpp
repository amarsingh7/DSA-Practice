class Solution {
public:
    bool valid(vector<vector<int>> &graph, vector<int> &visited, int f, int i)
    {
        // i is the node(garden) and f is flower
        if(visited[i])
            return false;
        for(auto child:graph[i])
        {
            if(visited[child]==f)
                return false;
        }
        return true;
    }
    
    bool help(vector<vector<int>> &graph, vector<int> &visited, int i, int n, int f)
    {
        // i is current node, n is total node, f is flower
        if(i==n+1)
            return true;
        for(int j=1; j<=4; j++)
        {
            if(valid(graph, visited, j, i))
            {
                visited[i]= j;
                if(help(graph, visited, i+1, n, f))
                    return true;
                else
                    visited[i]=0;
            }   
        
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n + 1);
        for (auto e : paths)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> flower(n + 1, 0);
        help(graph, flower, 0, n, 1);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            ans.push_back(flower[i]);
        return ans;
    }
};