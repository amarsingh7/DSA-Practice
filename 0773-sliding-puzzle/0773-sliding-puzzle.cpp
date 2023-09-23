class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) { 
        string end= "123450";
        vector<vector<int>> moves= {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 1, 5}, {2, 4}};
        
        string start = "";
        for(auto x:board){
            for(auto y:x)
                start+= to_string(y);
        }
        unordered_set<string> visited;
        visited.insert(start); 
        
        queue<pair<string, int>> q;
        q.push({start, 0});
        
        while(!q.empty())
        { 
            string cur= q.front().first;
            int dist= q.front().second; 
            q.pop();
            int index= cur.find("0");
            if(cur==end)
                return dist;
            for(auto &i:moves[index])
            {
                string next= cur;
                swap(next[index], next[i]);
                if(!visited.count(next))
                {
                    visited.insert(next);
                    q.push({next, dist+1});
                }
            }
        }
        return -1;
    }
};