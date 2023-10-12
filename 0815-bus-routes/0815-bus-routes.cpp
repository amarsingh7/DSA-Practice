class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int target) {
        int n= routes.size();
        int m= routes[0].size();
        if(src==target)
            return 0;
        unordered_map<int, vector<int>> adj;
        for(int route=0; route<routes.size(); route++)
        {
            for(auto stop:routes[route])
                adj[stop].push_back(route);
        }
        queue<int> q;
        unordered_set<int> vis;
        for(auto route:adj[src])
        {
            q.push(route);
            vis.insert(route);
        }
        int buscnt=1;
        while(q.size())
        {
            int sz= q.size();
            for(int i=0; i<sz; i++)
            {
                int route= q.front(); q.pop();
                for(auto stop:routes[route])
                {
                    if(stop==target)
                        return buscnt;
                    for(auto nextroute:adj[stop])
                    {
                        if(!vis.count(nextroute))
                        {
                            vis.insert(nextroute);
                            q.push(nextroute);
                        }
                    }
                }
            }
            buscnt++;
        }
        return -1;
    }
};