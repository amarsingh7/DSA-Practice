class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& req, vector<int> &indegree, int n, int i, int cnt)
    {
        if(i== req.size())
        {
            for(int i=0; i<n; i++)
            {
                if(indegree[i])
                    return;
            }
            ans= max(ans, cnt); 
            return;
        }
        indegree[req[i][0]]--;
        indegree[req[i][1]]++;
        dfs(req, indegree, n, i+1, cnt+1);
        
        indegree[req[i][0]]++;
        indegree[req[i][1]]--;
        dfs(req, indegree, n, i+1, cnt);
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> indegree(n, 0);
        dfs(requests, indegree, n, 0, 0);
        return ans;
    }
};