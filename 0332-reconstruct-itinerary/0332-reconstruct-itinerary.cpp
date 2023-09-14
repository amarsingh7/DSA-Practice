class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> ump;
    
    vector<string> ans;
    
    void dfs(string s)
    {
        auto &x= ump[s];
        while(!x.empty())
        {
            auto child= x.top();
            x.pop();
            dfs(child);
        }
        ans.emplace_back(s);
    }          
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // storing the directed edge wala graph in ump.
        // to make sure the lexico. order, used priority queue
        for(auto x:tickets)
        {
            string s= x[0];
            string d= x[1];
            
            ump[s].push(d);
        }
        dfs("JFK"); 
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};