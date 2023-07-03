class Solution {
public:
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
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<vector<int>> pq(numCourses);
        vector<int> indegree(numCourses, 0);
        int n= preq.size();
        for(int i=0; i<n; i++)
        {
            pq[preq[i][1]].push_back(preq[i][0]);
            indegree[preq[i][0]]++;
        }
        if(bfs(numCourses, pq, indegree))
            return true;
        return false;
    }
};