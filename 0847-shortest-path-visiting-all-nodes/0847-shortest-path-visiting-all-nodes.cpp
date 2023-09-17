class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int all = (1 << n) - 1;
        
        queue<pair<int, pair<int, int>>> q;
        set<pair<int, int>> vis;
        
        for(int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            pair<int, pair<int, int>> thisNode(i, make_pair(maskValue, 1));
            
            q.push(thisNode);
            vis.insert({i, maskValue});
        }
        
        while(!q.empty()) {
            pair<int, pair<int, int>> curr = q.front();
            q.pop();
            
            if(curr.second.first == all) {
                return curr.second.second - 1;
            }
            
            for(auto &adj: graph[curr.first]) {
                int bothVisitedMask = curr.second.first;
                bothVisitedMask = bothVisitedMask | (1 << adj);
                pair<int, pair<int, int>> ThisNode(adj, make_pair(bothVisitedMask, curr.second.second + 1));
                
                if(vis.find({adj, bothVisitedMask}) == vis.end()) {
                    vis.insert({adj, bothVisitedMask});
                    q.push(ThisNode);
                }
            }
        }
        
        return -1;
    }
};
