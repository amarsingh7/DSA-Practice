class Solution {
public:
    vector<int> ans;
    bool bfs(int n, vector<vector<int>> &adj, vector<int> &indegree)
    {
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            int cur= q.front();
            q.pop();
            ans.push_back(cur);
            for(auto child:adj[cur])
            {
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
            cnt++;
            
        }
        if(cnt !=n)
            return false;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        int n= preq.size();
        for(int i=0; i<n; i++)
        {
            adj[preq[i][1]].push_back(preq[i][0]);
            indegree[preq[i][0]]++;
        }
        if(bfs(numCourses, adj, indegree))
            return ans;
        return {};
        
    }
};