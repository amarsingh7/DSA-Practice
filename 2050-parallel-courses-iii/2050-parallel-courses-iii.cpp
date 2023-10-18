class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> ump;
        
        vector<int> indegree(n, 0);
        
        for(auto x:relations)
        {
            int a= x[0]-1;
            int b= x[1]-1;
            
            ump[a].push_back(b);
            indegree[b]++;
        }
        
        queue<int> q;
        vector<int> maxt(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0){
                q.push(i);
                maxt[i]= time[i];
            }  
        }
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            for(auto child:ump[node])
            {
                maxt[child]= max(maxt[child], maxt[node]+time[child]);
                indegree[child]--;
                if(indegree[child]==0)
                    q.push(child);
            }
        }
        int ans=0;
        for(auto x:maxt)
            ans= max(ans, x);
        return ans;
        
    }
};