class Solution {
public:
    bool isPathCrossing(string path) {
        int n= path.size();
        bool ans= false;
        int y=0, x=0;
        set<pair<int, int>> sp;
        sp.insert({x, y});
        for(auto p:path)
        {
            if(p=='N')  y++;
            else if(p=='E')  x++;
            else if(p=='S')  y--;
            else if(p=='W')  x--;
            if(sp.count({x, y}))
                return true;
            sp.insert({x, y});
        }
        
        return false;
    }
};