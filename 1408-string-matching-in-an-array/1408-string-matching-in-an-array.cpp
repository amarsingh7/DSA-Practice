class Solution {
public:
    
    vector<string> stringMatching(vector<string>& words) {
        vector<string> s;
        int n= words.size();
        for(auto i:words )
        {
            for(auto j:words)
            {
                if(i==j)  continue;
                if(j.find(i) != -1)
                {
                    s.push_back(i);
                    break;
                }
                    
            }
        }
        return s;
    }
};